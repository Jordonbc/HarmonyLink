mod v1;

mod version;
use version::info::Version;

mod api;

static PORT: u16 = 9000;

static USE_FALLBACK_DOCK_DETECTION: bool = false;

fn main() {

    //#[cfg(debug_assertions)]
    {
        let version_info = Version::get();
        println!("Version: {}", version_info.version);
        println!("Build Timestamp: {}", version_info.build_timestamp);
        println!("Git Branch: {}", version_info.git_branch);
        println!("Git Describe: {}", version_info.git_describe);
        println!("Git Commit Timestamp: {}", version_info.git_commit_timestamp);
        println!("Debug Build: {}", version_info.debug);
        println!("API versions: {}", version_info.supported_api_versions_to_string());

        println!("\n\n");
    }

    println!("HarmonyLink ©️ Jordon Brooks 2023");
    

    let sys = actix_web::rt::System::new();
    sys.block_on(async {
        let result = api::server::start_actix_web(PORT).expect("err");
        
        let _ = result.await;
    });
}
