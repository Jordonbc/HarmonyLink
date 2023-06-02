extern crate libloading;

fn main() {
    let lib = unsafe { match libloading::Library::new("harmony_link_core.dll") {
        Ok(lib) => lib,
        Err(err) => {
            eprintln!("Error loading DLL: {}", err);
            return;
        },
    }
    };

    unsafe {
        let func: libloading::Symbol<unsafe extern "C" fn()> = match lib.get(b"start") {
            Ok(func) => func,
            Err(err) => {
                eprintln!("Error finding function in DLL: {}", err);
                return;
            }
        };
        
        func();
    }
}
