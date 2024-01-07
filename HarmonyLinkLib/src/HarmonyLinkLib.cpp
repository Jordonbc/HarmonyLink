#include "HarmonyLinkLib.h"

#include <iostream>
#include "Platform/IPlatformUtilities.h"

namespace HarmonyLinkLib
{
    std::shared_ptr<IPlatformUtilities> PlatformUtilities = IPlatformUtilities::GetInstance();

    bool get_is_wine()
    {
        if (!PlatformUtilities)
        {
            std::wcout << "Failed to get platform utilities!\n";
            return false;
        }

        return PlatformUtilities->is_running_under_wine();
    }

    FCPUInfo* get_cpu_info()
    {
        if (!PlatformUtilities)
        {
            std::wcout << "Failed to get platform utilities!\n";
            return nullptr;
        }

        const std::shared_ptr<FCPUInfo> cpu_info = PlatformUtilities->get_cpu_info();
        if (!cpu_info)
        {
            return nullptr;
        }

        FCPUInfo* new_cpu_info = new FCPUInfo(*cpu_info);
        return new_cpu_info;
    }

    FDevice* get_device_info()
    {
        if (!PlatformUtilities)
        {
            std::wcout << "Failed to get platform utilities!\n";
            return nullptr;
        }

        const std::shared_ptr<FDevice> device = PlatformUtilities->get_device();
        if (!device)
        {
            return nullptr;
        }

        FDevice* new_device = new FDevice(*device);
        return new_device;
    }

    FOSVerInfo* get_os_version()
    {
    

        if (!PlatformUtilities)
        {
            std::wcout << "Failed to get platform utilities!\n";
            return nullptr;
        }

        const std::shared_ptr<FOSVerInfo> os_version_info = PlatformUtilities->get_os_version();
        if (!os_version_info)
        {
            return nullptr;
        }

        FOSVerInfo* new_os_info = new FOSVerInfo(*os_version_info);
        return new_os_info;
    }

    FBattery* get_battery_status()
    {
        if (!PlatformUtilities)
        {
            std::wcout << "Failed to get platform utilities!\n";
            return nullptr;
        }

        const std::shared_ptr<FBattery> new_battery = PlatformUtilities->get_battery_status();
        if (!new_battery)
        {
            return nullptr;
        }

        FBattery* battery = new FBattery(*new_battery);
        return battery;
    }
}
