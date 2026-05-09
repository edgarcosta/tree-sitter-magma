use crate::cli::FormatArgs;
use anyhow::{anyhow, Context, Result};
use lava_core::{format_str, FormatOptions};
use std::io::{Read, Write};
use std::path::Path;

pub async fn run(args: FormatArgs) -> Result<i32> {
    if args.recursive {
        anyhow::bail!("--recursive not yet implemented (Task 10)");
    }
    if args.check {
        anyhow::bail!("--check not yet implemented (Task 9)");
    }

    let opts = FormatOptions {
        query_override: args.query.clone(),
        cwd: None,
        tolerate_parse_errors: args.tolerate_parse_errors,
        skip_idempotence: false,
    };

    // Reading from stdin: zero paths, or a single `-`.
    let read_stdin = args.paths.is_empty()
        || (args.paths.len() == 1 && args.paths[0].as_os_str() == "-");
    if read_stdin {
        if args.write {
            anyhow::bail!("-w cannot be used with stdin");
        }
        let mut source = String::new();
        std::io::stdin()
            .read_to_string(&mut source)
            .context("reading stdin")?;
        let formatted = format_one(&source, "<stdin>", &opts)?;
        std::io::stdout()
            .write_all(formatted.as_bytes())
            .context("writing stdout")?;
        return Ok(0);
    }

    if !args.write && args.paths.len() > 1 {
        return Err(anyhow!(
            "refusing to concatenate multiple files to stdout; pass -w or one path at a time"
        ));
    }

    if args.write {
        for path in &args.paths {
            let source = std::fs::read_to_string(path)
                .with_context(|| format!("reading {}", path.display()))?;
            let formatted = format_one(&source, &path.display().to_string(), &opts)?;
            atomic_write(path, &formatted)
                .with_context(|| format!("writing {}", path.display()))?;
        }
        return Ok(0);
    }

    // Single file → stdout.
    let path = &args.paths[0];
    let source = std::fs::read_to_string(path)
        .with_context(|| format!("reading {}", path.display()))?;
    let formatted = format_one(&source, &path.display().to_string(), &opts)?;
    std::io::stdout()
        .write_all(formatted.as_bytes())
        .context("writing stdout")?;
    Ok(0)
}

fn format_one(source: &str, label: &str, opts: &FormatOptions) -> Result<String> {
    let (formatted, src) = format_str(source, opts)
        .map_err(|e| anyhow!("{}", e))
        .with_context(|| format!("formatting {label}"))?;
    tracing::debug!(?src, "format_one done");
    Ok(formatted)
}

fn atomic_write(target: &Path, contents: &str) -> std::io::Result<()> {
    let parent = target.parent().unwrap_or(Path::new("."));
    let mut tmp = tempfile::Builder::new()
        .prefix(".lava-")
        .suffix(".tmp")
        .tempfile_in(parent)?;
    tmp.write_all(contents.as_bytes())?;
    tmp.flush()?;
    tmp.persist(target).map_err(|e| e.error)?;
    Ok(())
}
