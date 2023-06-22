use serde::{Deserialize, Serialize};
use crate::{os, battery, docking::{self, structs::DockInfo}, version};

#[derive(Deserialize, Serialize)]
pub struct Allinfo {
    pub os: os::structs::OSInfo,
    pub battery: battery::structs::BatteryInfo,
    pub dock: docking::structs::DockInfo,
    pub version: version::info::Version
}

impl Allinfo {
    pub fn new() -> Allinfo {
        Allinfo { os: os::structs::OSInfo::new(),
            battery: battery::structs::BatteryInfo::new(),
            dock: DockInfo::new(),
            version: version::info::Version::get()
        }
    }
}