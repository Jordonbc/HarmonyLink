use std::env;
use std::fs;
use std::path::Path;

fn main() {
    // The directory of the Cargo manifest of the package that is currently being built.
    let manifest_dir = env::var("CARGO_MANIFEST_DIR").expect("CARGO_MANIFEST_DIR is not defined");

    // The directory where the final binaries will be placed.
    let profile = env::var("PROFILE").expect("PROFILE is not defined");
    let out_dir = Path::new(&manifest_dir).join("target").join(profile);

    // The Resources directory.
    let resources_dir = Path::new(&manifest_dir).join("Resources");

    // Ensure the Resources directory exists.
    if !resources_dir.exists() {
        panic!("Resources directory does not exist");
    }

    // Iterate over each entry in the Resources directory.
    for entry in fs::read_dir(resources_dir).expect("read_dir call failed") {
        let entry = entry.expect("entry is invalid");
        let path = entry.path();
        if path.is_file() {
            // The destination path is the output directory plus the file name.
            let dest_path = out_dir.join(path.file_name().expect("file has no name"));
            // Copy the file.
            fs::copy(&path, &dest_path).expect("copy failed");
        }
    }

    println!("cargo:rustc-env=RUSTFLAGS=-C link-arg=-Wl,-rpath,$ORIGIN");
    println!("cargo:rerun-if-changed=src/main.rs");
}
