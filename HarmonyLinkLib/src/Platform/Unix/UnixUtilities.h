#pragma once

#include "Platform/IPlatformUtilities.h"
namespace HarmonyLinkLib
{
    class UnixUtilities : public IPlatformUtilities {
    public:
        bool is_running_under_wine() override;

        std::shared_ptr<FCPUInfo> get_cpu_info() override;
        std::shared_ptr<FBattery> get_battery_status() override;
        std::shared_ptr<FOSVerInfo> get_os_version() override;
        
        // Implementation for other Unix/Linux-specific functions
    };
}
