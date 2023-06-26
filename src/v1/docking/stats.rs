use std::{io::BufReader, fs::File};

#[allow(unused_imports)]
use std::collections::HashSet;

use crate::{v1::{battery::{stats::get_battery_info, structs::ChargingStatus}}, USE_FALLBACK_DOCK_DETECTION};

use super::structs::{Dock, DockInfo};

/* This will get the current dock info. */
pub fn get_dock_info() -> Result<DockInfo, Box<dyn std::error::Error>> {
    let mut dock = DockInfo::new();
    dock.dock_info = get_dock()?;

    dock.is_docked = dock.dock_info.brand == String::new() && dock.dock_info.model == String::new();

    /*
    This code will manually detect a dock if it wasn't automatically picked up by get_dock().
    The code currently doesnt work. To manually detect a dock we will detect the presence of
    a battery, charging of the handheld, and eventually when I find a cross-platform create,
    it will also detect the presence of an external monitor (will most likely only work on a
    Steam Deck for now)
     */
    if USE_FALLBACK_DOCK_DETECTION {
        if !dock.is_docked {
            dock.fallback_detection = true;
    
            let battery_info = get_battery_info()?;
    
            if battery_info.has_battery && battery_info.charging_status == ChargingStatus::Charging {
            }
        }   
    }

    Ok(dock)
}

/* Reads the dock_models.json file and returns a vector of structs with the data */
#[allow(dead_code)]
pub fn read_dock_models_from_file() -> Result<Vec<Dock>, Box<dyn std::error::Error>> {
    let file = File::open("Resources/dock_models.json")?;
    let reader = BufReader::new(file);
    let dock_models: Vec<Dock> = serde_json::from_reader(reader)?;
    Ok(dock_models)
}

#[cfg(target_os = "linux")]
/* This will detect the dock model and brand. */
pub fn get_dock() -> Result<Dock, Box<dyn std::error::Error>> {
    let devices = rusb::devices()?;
    let dock_models = read_dock_models_from_file()?;

    for dock_model in dock_models {
        let mut found_components = HashSet::new();

        for device in devices.iter() {
            let device_desc = device.device_descriptor()?;
            let device_id = (device_desc.vendor_id(), device_desc.product_id());

            // Check if the device is one of the components of the dock.
            if dock_model.usb_ids.contains(&[device_desc.vendor_id(), device_desc.product_id()]) {
                found_components.insert(device_id);
                println!("(get_dock) Detected: {}", serde_json::to_string_pretty(&device_id)?);
            }
        }

        if found_components.len() == dock_model.usb_ids.len() {
            println!("(get_dock) All components detected for {}", serde_json::to_string_pretty(&dock_model)?);
            return Ok(Dock {
                model: dock_model.model.clone(),
                brand: dock_model.brand.clone(),
                usb_ids: dock_model.usb_ids.clone()
            });
        }
    }
    Ok(Dock::new())
}

#[cfg(target_os = "macos")]
/* This will detect the dock model and brand. */
pub fn get_dock() -> Result<Dock, Box<dyn std::error::Error>> {
    Ok(Dock::new())
    //Err(Box::new(std::io::Error::new(std::io::ErrorKind::Other, "Incorrect OS")))
}

/* This will detect the dock model and brand. */
#[cfg(target_os = "windows")]
pub fn get_dock() -> Result<Dock, Box<dyn std::error::Error>> {
    Ok(Dock::new())
}