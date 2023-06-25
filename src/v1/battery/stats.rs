use crate::v1::battery::structs::ChargingStatus;

use super::structs::BatteryInfo;

pub fn get_battery_info() -> Result<BatteryInfo, Box<dyn std::error::Error>> {
    let mut battery_info = BatteryInfo { has_battery: false, battery_percent: 0, charging_status: ChargingStatus::UNKNOWN };
    
    let manager = battery::Manager::new().unwrap();

    battery_info.has_battery = manager.batteries().unwrap().count() > 0;

    if !battery_info.has_battery {
        return Ok(battery_info);
    }

    for (idx, battery) in manager.batteries()?.enumerate() {
        let battery = battery?;
        let state = battery.state();
        let energy = battery.energy();
        let full_energy = battery.energy_full();
        let state_of_charge = (energy / full_energy).get::<battery::units::ratio::percent>();
        
        println!("Battery #{}:", idx);
        println!("Charging status: {:?}", state);
        println!("Charge level: {:.2}%", state_of_charge);

        battery_info.battery_percent = state_of_charge.round() as i8;
        battery_info.charging_status = match state {
            battery::State::Charging => ChargingStatus::Charging,
            battery::State::Discharging => ChargingStatus::Battery,
            battery::State::Empty => ChargingStatus::Battery,
            battery::State::Full => ChargingStatus::Battery,
            _ => ChargingStatus::UNKNOWN,
        }
    }
    
    Ok(battery_info)
}