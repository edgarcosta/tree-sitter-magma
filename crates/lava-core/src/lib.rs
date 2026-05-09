//! Library powering the lava CLI: format, query resolution, and error types.

pub mod error;
pub mod format;
pub mod queries;

pub use error::{Error, QuerySource, Result};
pub use format::{FormatOptions, format_str};
