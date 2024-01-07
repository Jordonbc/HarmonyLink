#pragma once

#include "Platform/IPlatformUtilities.h"

namespace HarmonyLinkLib
{
    class WindowsUtilities : public IPlatformUtilities
    {
    public:
        std::shared_ptr<FBattery> get_battery_status() override;

        std::shared_ptr<FCPUInfo> get_cpu_info() override;
    
        std::shared_ptr<FOSVerInfo> get_os_version() override;
    };
}
