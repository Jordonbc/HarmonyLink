﻿// Copyright (c) 2024 Jordon Brooks
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

#include "WindowsUtilities.h"

#include <sstream>
#include <Windows.h>

#include "Platform/WineUtilities.h"

namespace HarmonyLinkLib
{
    std::shared_ptr<FBattery> WindowsUtilities::get_battery_status()
{
    if (is_linux())
    {
       return WineUtilities::get_battery_status();
    }
    FBattery result;
    
    SYSTEM_POWER_STATUS status;
    if (GetSystemPowerStatus(&status)) {
        result.has_battery = status.BatteryFlag != 128; // 128 indicates no battery
        result.is_connected_to_ac = status.ACLineStatus == 1;
        result.battery_percent = result.has_battery ? status.BatteryLifePercent : 0;
    } else {
        std::wcout << "Failed to get power statistics.\n";
    }

    return std::make_shared<FBattery>(result);
}

std::shared_ptr<FCPUInfo> WindowsUtilities::get_cpu_info()
{
    if (is_linux())
    {
        return WineUtilities::get_cpu_info();
    }
    
    return {};
}

std::shared_ptr<FOSVerInfo> WindowsUtilities::get_os_version()
{
    if (is_linux())
    {
        return WineUtilities::get_linux_info();
    }
    
    OSVERSIONINFOEX os_version_info;
    ZeroMemory(&os_version_info, sizeof(OSVERSIONINFOEX));
    os_version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (!GetVersionEx(reinterpret_cast<OSVERSIONINFO*>(&os_version_info))) {
        // Handle error if needed
        return nullptr;
    }

    FOSVerInfo os_version;

    HKEY h_key;
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion"), 0, KEY_READ, &h_key) == ERROR_SUCCESS)
    {
        DWORD dw_size;
        DWORD dw_type;
        char sz_product_name[256];
        dw_size = sizeof(sz_product_name);
        if (RegQueryValueEx(h_key, TEXT("ProductName"), nullptr, &dw_type, reinterpret_cast<LPBYTE>(sz_product_name), &dw_size) == ERROR_SUCCESS)
        {
            os_version.pretty_name = sz_product_name;
        }
        RegCloseKey(h_key);
    }

    std::stringstream version;
    version << os_version_info.dwMajorVersion << "." << os_version_info.dwMinorVersion;
    os_version.version_id = version.str();

    os_version.name = "Windows";
    os_version.version = os_version_info.dwBuildNumber; // Build number as the version

    return std::make_shared<FOSVerInfo>(os_version);
}
}
