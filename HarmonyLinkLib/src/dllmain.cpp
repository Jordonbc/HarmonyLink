// Copyright (c) 2024 Jordon Brooks
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//   http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include "Version.h"

namespace HarmonyLinkLib
{
    void HarmonyLinkInit()
    {
        std::wcout << "HarmonyLink V" << version::ToString().c_str() << " Copyright (C) 2023 Jordon Brooks\n";
    }
}


#if BUILD_WINDOWS
#include <windows.h>

// Standard DLL entry point
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        // Code to run when the DLL is loaded
        HarmonyLinkLib::HarmonyLinkInit();
        break;
    case DLL_THREAD_ATTACH:
        // Code to run when a thread is created during the DLL's lifetime
    case DLL_THREAD_DETACH:
        // Code to run when a thread ends normally.
    case DLL_PROCESS_DETACH:
        // Code to run when the DLL is unloaded
    default:
        break;
    }
    return TRUE; // Successful DLL_PROCESS_ATTACH.
}
#endif

#if BUILD_UNIX
__attribute__((constructor))
static void onLibraryLoad() {
    // Code to run when the library is loaded
    HarmonyLinkLib::HarmonyLinkInit();
}

__attribute__((destructor))
static void onLibraryUnload() {
    // Code to run when the library is unloaded
}
#endif
