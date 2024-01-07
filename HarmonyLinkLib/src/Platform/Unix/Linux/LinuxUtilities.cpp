#include "LinuxUtilities.h"


#include <fstream>
#include <string>
#include "Platform/WineUtilities.h"

namespace HarmonyLinkLib
{
    std::shared_ptr<FBattery> LinuxUtilities::get_battery_status()
    {
        return WineUtilities::get_battery_status();
    }

    std::shared_ptr<FOSVerInfo> LinuxUtilities::get_os_version()
    {
        return WineUtilities::get_linux_info();
    }

    std::shared_ptr<FCPUInfo> LinuxUtilities::get_cpu_info()
    {
        return WineUtilities::get_cpu_info();
    }
}
