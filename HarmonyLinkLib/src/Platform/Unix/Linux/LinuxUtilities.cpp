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
