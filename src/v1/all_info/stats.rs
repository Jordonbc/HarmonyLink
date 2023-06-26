use crate::v1::docking;
use crate::v1::battery;
use crate::v1::os;
use crate::version;

use super::structs::Allinfo;

/* This will query all the modules and return all the combined data */
pub fn get_all_info() -> Result<Allinfo, Box<dyn std::error::Error>> {
    let mut all_info = Allinfo::new();
    
    all_info.dock = docking::stats::get_dock_info()?;
    all_info.battery = battery::stats::get_battery_info()?;
    all_info.os = os::stats::get_os()?;
    all_info.version = version::info::Version::get();

    Ok(all_info)
}