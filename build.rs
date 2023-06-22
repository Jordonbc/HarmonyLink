use std::env;
use std::error::Error;
use std::fs;
use std::path::Path;

use vergen::EmitBuilder;

fn copy_resources() -> Result<(), Box<dyn Error>> {
    // The directory of the Cargo manifest of the package that is currently being built.
    let manifest_dir = env::var("CARGO_MANIFEST_DIR").expect("CARGO_MANIFEST_DIR is not defined");

    // The directory where the final binaries will be placed.
    let profile = env::var("PROFILE")?;
    let out_dir = Path::new(&manifest_dir).join("target").join(profile).join("Resources");

    if !out_dir.exists() {
        fs::create_dir(&out_dir)?;
    }

    // The Resources directory.
    let resources_dir = Path::new(&manifest_dir).join("Resources");

    // Ensure the Resources directory exists.
    if !resources_dir.exists() {
        panic!("Resources directory does not exist");
    }

    // Iterate over each entry in the Resources directory.
    for entry in fs::read_dir(resources_dir)? {
        let entry = entry?;
        let path = entry.path();
        if path.is_file() {
            // The destination path is the output directory plus the file name.
            let dest_path = out_dir.join(path.file_name().expect("file has no name"));
            // Copy the file.
            fs::copy(&path, &dest_path)?;
        }
    }

    Ok(())
}

#[cfg(windows)]
fn windows_resource() -> Result<(), Box<dyn Error>> {
    let mut res = winres::WindowsResource::new();
    res.set_icon("res/HarmonyLinkLogo.ico");
    res.compile()?;
    Ok(())
}

#[cfg(unix)]
fn windows_resource() -> Result<(), Box<dyn Error>> {
    Ok(())
}

fn main() -> Result<(), Box<dyn Error>> {
    // Emit the instructions
    EmitBuilder::builder()
        .all_build()
        .all_cargo()
        .all_git()
        .all_rustc()
        .all_sysinfo()
        .emit()?;

    // Copy the Resources folder
    copy_resources()?;

    windows_resource()?;

    Ok(())
}
