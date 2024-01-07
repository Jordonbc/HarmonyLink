#pragma once

#include "Structs/FOSVerInfo.h"

#include "Platform/Unix/UnixUtilities.h"

namespace HarmonyLinkLib
{
    class LinuxUtilities : public UnixUtilities {
    public:
        // Implementation for other Linux-specific functions
        std::shared_ptr<FBattery> get_battery_status() override;
        
        std::shared_ptr<FOSVerInfo> get_os_version() override;

        std::shared_ptr<FCPUInfo> get_cpu_info() override;

        bool is_linux() override
        {
            return true;
        }
    };
}
