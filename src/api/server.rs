use actix_web::HttpServer;

use crate::api::endpoints::*;

#[allow(dead_code)]
pub async fn stop_actix_web(server: actix_web::dev::Server) -> std::io::Result<()> {
    println!("Stopping server.");
    server.handle().stop(true).await;
    Ok(())
}

pub fn start_actix_web(port: u16) -> std::io::Result<actix_web::dev::Server> {

    println!("Starting webserver on 127.0.0.1:{}", port);

    let server = HttpServer::new(move || {
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
    .run();

    Ok(server)
}
