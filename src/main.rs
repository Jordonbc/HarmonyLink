extern crate libloading;

fn main() {
    // Use `cfg!` macro to detect OS
    let lib_path = if cfg!(target_os = "windows") {
        "harmony_link_core.dll"
    } else if cfg!(target_os = "linux") {
        "libharmony_link_core.so"
    } else {
        eprintln!("Unsupported OS");
        return;
    };

    let lib = unsafe { match libloading::Library::new(lib_path) {
        Ok(lib) => lib,
        Err(err) => {
            eprintln!("Error loading dynamic library: {}", err);
            return;
        },
    }
    };

    unsafe {
        let func: libloading::Symbol<unsafe extern "C" fn()> = match lib.get(b"start") {
            Ok(func) => func,
            Err(err) => {
                eprintln!("Error finding function in dynamic library: {}", err);
                return;
            }
        };
        
        func();
    }
}
