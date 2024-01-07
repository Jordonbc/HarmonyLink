#include "UnixUtilities.h"

namespace HarmonyLinkLib
{
    bool UnixUtilities::is_running_under_wine()
    {
    return false;
    }

    std::shared_ptr<FCPUInfo> UnixUtilities::get_cpu_info()
    {
        return nullptr;
    }

    std::shared_ptr<FBattery> UnixUtilities::get_battery_status()
    {
        return nullptr;
    }

    std::shared_ptr<FOSVerInfo> UnixUtilities::get_os_version()
    {
        return nullptr;
    }
}