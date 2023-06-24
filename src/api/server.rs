use actix_web::{HttpServer, web};

use crate::api::endpoints_v1;

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
        .service(web::scope("/v1").configure(endpoints_v1::configure))
    })
    .bind(("127.0.0.1", port))?
    .run();

    Ok(server)
}
