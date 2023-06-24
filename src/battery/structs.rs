use serde::{Deserialize, Serialize};

#[derive(Deserialize, Serialize, PartialEq, Clone)]
pub enum ChargingStatus {
    Charging,
    Battery,
    UNKNOWN,
}

#[derive(Deserialize, Serialize, Clone)]
pub struct BatteryInfo {
    pub has_battery: bool,
    pub battery_percent: i8,
    pub charging_status: ChargingStatus,
}

impl BatteryInfo {
    pub fn new() -> BatteryInfo {
        BatteryInfo { 
            has_battery: false,
            battery_percent: 0,
            charging_status: ChargingStatus::UNKNOWN
        }
    }
    pub fn to_string(self) -> String {
        serde_json::to_string(&self).expect("Failed to parse into string")
    }
}