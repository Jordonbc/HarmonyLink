mod battery;
mod docking;
mod os;

mod version;
use version::info::Version;

mod api;

static PORT: u16 = 9000;

static USE_FALLBACK_DOCK_DETECTION: bool = false;

fn main() {
    let version_info = Version::get();

    println!("Version: {}", version_info.version);
    println!("Build Timestamp: {}", version_info.build_timestamp);
    println!("Git Branch: {}", version_info.git_branch);
    println!("Git Describe: {}", version_info.git_describe);
    println!("Git Commit Timestamp: {}", version_info.git_commit_timestamp);
    println!("Debug Build: {}", version_info.debug);
    println!("\n\n");

    println!("HarmonyLink ©️ Jordon Brooks 2023");
    

    let sys = actix_web::rt::System::new();
    sys.block_on(async {
        let result = api::server::start_actix_web (PORT).await;
        match result {
            Ok(_) => println!("Webserver started successfully."),
            Err(e) => println!("Error starting actix_web: {}", e),
        }
    });
}
