#pragma once

#include "Structs/FBattery.h"
#include "Structs/FCPUInfo.h"
#include "Structs/FDevice.h"
#include "Structs/FOSVerInfo.h"

namespace HarmonyLinkLib
{
    class IPlatformUtilities {
    public:
        static std::shared_ptr<IPlatformUtilities>& GetInstance();

        IPlatformUtilities() = default;
        IPlatformUtilities(const IPlatformUtilities& other) = default;
        IPlatformUtilities(IPlatformUtilities&& other) = default;
        IPlatformUtilities& operator=(const IPlatformUtilities& other) = default;
        IPlatformUtilities& operator=(IPlatformUtilities&& other) = default;
        virtual ~IPlatformUtilities() = default;
    
        // General OS-level functions
        virtual bool is_running_under_wine();
        virtual bool is_linux();
    
        virtual std::shared_ptr<FDevice> get_device();
        virtual std::shared_ptr<FCPUInfo> get_cpu_info() = 0;
        virtual std::shared_ptr<FBattery> get_battery_status() = 0;
        virtual std::shared_ptr<FOSVerInfo> get_os_version() = 0;

        bool is_steam_deck(const FDevice& device);

        // Add more virtual functions for other OS interactions here
    };
}
