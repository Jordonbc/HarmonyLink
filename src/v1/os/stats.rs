use super::structs::{OSInfo, Platform, Architecture};

pub fn get_platform() -> Platform {
    if cfg!(target_os = "windows") {
        Platform::WINDOWS
    } else if cfg!(target_os = "macos") {
        Platform::MAC
    } else if cfg!(target_os = "linux") {
        Platform::LINUX
    } else {
        Platform::UNKNOWN
    }
}


pub fn get_os() -> Result<OSInfo, Box<dyn std::error::Error>> {
    let mut temp = OSInfo::new();
    let info = os_info::get();

    temp.platform = get_platform();

    temp.name = match info.codename() {
        Some(s) => s.to_string(),
        _ => String::new(),
    };

    temp.version = info.version().to_string();

    if temp.name == String::new() {
        temp.name = match info.edition() {
            Some(s) => s.to_string(),
            _ => String::new(),
        };
    }

    temp.bits = match info.bitness() 
    {
        os_info::Bitness::X32 => Architecture::X86,
        os_info::Bitness::X64 => Architecture::X86_64,
        _ => Architecture::UNKNOWN,
    };

    Ok(temp)
    
}