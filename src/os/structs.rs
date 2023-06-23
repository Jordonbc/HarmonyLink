use serde::{Deserialize, Serialize};

#[derive(Deserialize, Serialize, Debug, PartialEq)]
pub enum Platform {
    WINDOWS = 0,
    LINUX = 1,
    MAC = 2,
    UNKNOWN = 255
}

#[derive(Deserialize, Serialize)]
pub enum Architecture {
    X86 = 0,
    X86_64 = 1,
    UNKNOWN = 255,
}

#[derive(Deserialize, Serialize)]
pub struct OSInfo {
    pub platform: Platform, // Windows, Mac, Linux
    pub name: String, // "Windows 11 2306", "Ubuntu 22.04 LTS"
    pub version: String, // 2306, 22.04
    pub bits: Architecture // 32, 64
}

impl OSInfo {
    pub fn new() -> OSInfo {
        OSInfo {
            platform: Platform::UNKNOWN,
            name: String::new(),
            version: String::new(),
            bits: Architecture::UNKNOWN
        }
    }
}