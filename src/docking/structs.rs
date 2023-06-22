use serde::{Deserialize, Serialize};

#[derive(Deserialize, Serialize)]
pub struct Dock {
    pub brand: String, // ex: JSAUX
    pub model: String, // ex: HB0603
    pub usb_ids: Vec<[u16; 2]>,
}

impl Dock {
    pub fn new() -> Dock {
        Dock { brand: String::new(), 
            model: String::new(),
            usb_ids: vec![],
        }
    }
}

#[derive(Deserialize, Serialize)]
pub struct DockInfo {
    pub dock_info: Dock,
    pub is_docked: bool,
    pub fallback_detection: bool,
}

impl DockInfo {
    pub fn new() -> DockInfo {
        DockInfo { dock_info: Dock::new(),
            is_docked: false,
            fallback_detection: false
        }
    }
}