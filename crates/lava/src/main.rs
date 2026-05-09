mod cli;
mod cmd;

use clap::Parser;
use cli::{Cli, Command};
use tracing_subscriber::EnvFilter;

#[tokio::main(flavor = "current_thread")]
async fn main() {
    tracing_subscriber::fmt()
        .with_env_filter(
            EnvFilter::try_from_env("LAVA_LOG").unwrap_or_else(|_| EnvFilter::new("warn")),
        )
        .with_writer(std::io::stderr)
        .init();

    let cli = Cli::parse();
    let exit_code = match dispatch(cli).await {
        Ok(code) => code,
        Err(err) => {
            eprintln!("lava: {err:#}");
            2
        }
    };
    std::process::exit(exit_code);
}

async fn dispatch(cli: Cli) -> anyhow::Result<i32> {
    match cli.command {
        Command::Format(args) => cmd::format::run(args).await,
        Command::Highlight => cmd::highlight::run().await,
        Command::Parse => cmd::parse::run().await,
    }
}
