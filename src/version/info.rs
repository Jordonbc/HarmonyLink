use serde::{Deserialize, Serialize};

#[derive(Deserialize, Serialize)]
pub struct Version {
    pub build_timestamp: String,
    pub git_branch: String,
    pub git_describe: String,
    pub git_commit_timestamp: String,
    pub debug: bool,
    pub version: String,
    pub version_major: i32,
    pub version_minor: i32,
    pub version_patch: i32,
    pub version_pre: String
}

impl Version {
    pub fn get() -> Version {
        Version {
        build_timestamp: env!("VERGEN_BUILD_TIMESTAMP").to_string(),
        git_branch: env!("VERGEN_GIT_BRANCH").to_string(),
        git_describe: env!("VERGEN_GIT_DESCRIBE").to_string(),
        git_commit_timestamp: env!("VERGEN_GIT_COMMIT_TIMESTAMP").to_string(),
        debug: env!("VERGEN_CARGO_DEBUG").parse().unwrap(),
        version: env!("CARGO_PKG_VERSION").to_string(),
        version_major: env!("CARGO_PKG_VERSION_MAJOR").parse().unwrap(),
        version_minor: env!("CARGO_PKG_VERSION_MINOR").parse().unwrap(),
        version_patch: env!("CARGO_PKG_VERSION_PATCH").parse().unwrap(),
        version_pre: env!("CARGO_PKG_VERSION_PRE").parse().unwrap()
        }
    }
}