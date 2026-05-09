use clap::{Parser, Subcommand};
use std::path::PathBuf;

#[derive(Parser, Debug)]
#[command(
    name = "lava",
    version,
    about = "A community-maintained multi-tool for the Magma language",
    long_about = "lava is a single-binary CLI offering formatter, highlighter,\n\
                  and parsing tools for Magma. Use `lava <subcommand> --help` for\n\
                  per-subcommand options."
)]
pub struct Cli {
    #[command(subcommand)]
    pub command: Command,
}

#[derive(Subcommand, Debug)]
pub enum Command {
    /// Format Magma source files
    #[command(alias = "fmt")]
    Format(FormatArgs),

    /// Output syntax-highlighted HTML (planned for v0.2)
    #[command(alias = "hl")]
    Highlight,

    /// Parse a file and print the syntax tree (planned for v0.2)
    Parse,
}

#[derive(clap::Args, Debug)]
pub struct FormatArgs {
    /// Files to format. With zero paths or `-`, reads stdin.
    pub paths: Vec<PathBuf>,

    /// Rewrite files in place (atomic).
    #[arg(short = 'w', long)]
    pub write: bool,

    /// Exit 1 if any file would change; do not modify files.
    #[arg(long, conflicts_with = "write")]
    pub check: bool,

    /// Print a unified diff alongside --check (default: paths only).
    #[arg(long, requires = "check")]
    pub diff: bool,

    /// Path to a custom magma.scm query file.
    #[arg(long, value_name = "PATH")]
    pub query: Option<PathBuf>,

    /// Format files containing parse errors on a best-effort basis.
    #[arg(long)]
    pub tolerate_parse_errors: bool,

    /// Recurse into directories (respects .gitignore and .lavaignore).
    #[arg(short = 'r', long)]
    pub recursive: bool,

    /// Filename to display in diagnostics when reading from stdin.
    #[arg(long, value_name = "PATH")]
    pub stdin_filename: Option<PathBuf>,
}
