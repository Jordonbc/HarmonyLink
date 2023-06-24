use actix_web::web;
use actix_web::{HttpResponse, get};

use crate::docking;
use crate::version;
use crate::battery;

#[get("/are_you_there")]
pub async fn index() -> HttpResponse {
    HttpResponse::Ok().body("yes")
}

#[get("/all_info")]
pub async fn get_all_info() -> HttpResponse {
    match crate::api::all_info::get_all_info() {
        Ok(info) => {

            #[cfg(debug_assertions)]
            {
                println!("Successfully got all info: {}", &info.clone().to_string());
            }
            HttpResponse::Ok().json(&info)
        },
        Err(err) => {
            eprintln!("Failed to get all info: {}", err);
            HttpResponse::InternalServerError().body(format!("Failed to get device info: {}", err))
        }
    }
}

#[get("/dock_info")]
pub async fn get_dock_info() -> HttpResponse {
    match docking::stats::get_dock() {
        Ok(info) => {
            #[cfg(debug_assertions)]
            {
                println!("Successfully got dock info: {}", &info.clone().to_string());
            }
            HttpResponse::Ok().json(&info)
        },
        Err(err) => {
            eprintln!("Failed to get dock info: {}", err);
            HttpResponse::InternalServerError().body(format!("Failed to get dock info: {}", err))
        }
    }
}


#[get("/os_info")]
pub async fn get_os_info() -> HttpResponse {
    match crate::os::stats::get_os() {
        Ok(info) => {
            #[cfg(debug_assertions)]
            {
                println!("Successfully got os info: {}", &info.clone().to_string());
            }
            HttpResponse::Ok().json(&info)
        },
        Err(err) => {
            eprintln!("Failed to get os info: {}", err);
            HttpResponse::InternalServerError().body(format!("Failed to get OS info: {}", err))
        }
    }
}

#[get("/battery_info")]
pub async fn get_battery_info() -> HttpResponse {
    match battery::stats::get_battery_info() {
        Ok(info) => {
            #[cfg(debug_assertions)]
            {
                println!("Successfully got battery info: {}", &info.clone().to_string());
            }
            HttpResponse::Ok().json(&info)
        },
        Err(err) => {
            eprintln!("Failed to get battery info: {}", err);
            HttpResponse::InternalServerError().body(format!("Failed to get battery info: {}", err))
        }
    }
}

#[get("/version_info")]
pub async fn get_version_info() -> HttpResponse {
    #[cfg(debug_assertions)]
    {
        println!("Successfully got version info: {}", version::info::Version::get().to_string());
    }
    HttpResponse::Ok().json(&version::info::Version::get())
}

pub fn configure(cfg: &mut web::ServiceConfig) {
    cfg.service(get_all_info);
    cfg.service(get_dock_info);
    cfg.service(get_os_info);
    cfg.service(get_battery_info);
    cfg.service(get_version_info);
    // Register other version 1 handlers here...
}