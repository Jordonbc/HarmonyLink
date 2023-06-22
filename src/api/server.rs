use actix_web::HttpServer;

use crate::api::endpoints::*;

pub async fn start_actix_web(port: u16) -> std::io::Result<()> {

    //std::env::set_var("RUST_LOG", "debug");
    //std::env::set_var("RUST_BACKTRACE", "1");

    println!("Starting webserver on 127.0.0.1:{}", port);

    HttpServer::new(move || {
        let logger = actix_web::middleware::Logger::default();
        actix_web::App::new()
        .wrap(logger)
        .service(index)
        .service(get_all_info)
        .service(get_os_info)
        .service(get_battery_info)
        .service(get_version_info)
        .service(get_dock_info)
    })
    .bind(("127.0.0.1", port))?
    .run()
    .await
}