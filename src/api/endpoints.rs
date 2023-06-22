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
            HttpResponse::Ok().json(&info)
        },
        Err(err) => {
            HttpResponse::InternalServerError().body(format!("Failed to get device info: {}", err))
        }
    }
}

#[get("/dock_info")]
pub async fn get_dock_info() -> HttpResponse {
    match docking::stats::get_dock() {
        Ok(info) => {
            HttpResponse::Ok().json(&info)
        },
        Err(err) => {
            HttpResponse::InternalServerError().body(format!("Failed to get dock info: {}", err))
        }
    }
}


#[get("/os_info")]
pub async fn get_os_info() -> HttpResponse {
    match crate::os::stats::get_os() {
        Ok(info) => {
            HttpResponse::Ok().json(&info)
        },
        Err(err) => {
            HttpResponse::InternalServerError().body(format!("Failed to get OS info: {}", err))
        }
    }
}

#[get("/battery_info")]
pub async fn get_battery_info() -> HttpResponse {
    match battery::stats::get_battery_info() {
        Ok(info) => {
            HttpResponse::Ok().json(&info)
        },
        Err(err) => {
            HttpResponse::InternalServerError().body(format!("Failed to get battery info: {}", err))
        }
    }
}

#[get("/version_info")]
pub async fn get_version_info() -> HttpResponse {

    HttpResponse::Ok().json(&version::info::Version::get())
}