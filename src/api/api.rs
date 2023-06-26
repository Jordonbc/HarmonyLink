use actix_web::{HttpResponse, get, web};

use crate::version::info::Version;

#[get("/supported_versions")]
pub async fn versions() -> HttpResponse {
    let version = Version::get();
    HttpResponse::Ok().json(&version.supported_api_versions)
}

pub fn configure(cfg: &mut web::ServiceConfig) {
    cfg.service(versions);
    // Register other version 1 handlers here...
}