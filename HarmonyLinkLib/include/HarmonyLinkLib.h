// Copyright (C) 2023  Jordon Brooks


/**
 * IMPORTANT REMINDER:
 * Do NOT use standard output functions like std::cout and printf anywhere in this codebase.
 *
 * Reason:
 * Unreal Engine 5's packaging tool encounters issues with these functions, leading to 
 * packaging failures. The engine sets stdout to UTF-8, which can cause conflicts with
 * these standard functions, resulting in a "SECURE CRT: Invalid parameter detected" error 
 * during packaging.
 *
 * This issue once required an extensive debugging effort that lasted over 8 hours. 
 * To prevent similar issues in the future and ensure smooth packaging, always use 
 * wide-character versions of these functions, such as wprintf and std::wcout, when working 
 * within the DLL. These functions are compatible with the UTF-8 setting in Unreal Engine 5.
 *
 */


#pragma once

#include "Core.h"
#include "Structs/FBattery.h"
#include "Structs/FCPUInfo.h"
#include "Structs/FDevice.h"
#include "Structs/FOSVerInfo.h"


class IPlatformUtilities;

namespace HarmonyLinkLib
{
    extern "C" HARMONYLINKLIB_API bool get_is_wine();

    extern "C" HARMONYLINKLIB_API FCPUInfo* get_cpu_info();

    extern "C" HARMONYLINKLIB_API FDevice* get_device_info();

    extern "C" HARMONYLINKLIB_API FOSVerInfo* get_os_version();
    
    extern "C" HARMONYLINKLIB_API FBattery* get_battery_status();
}
