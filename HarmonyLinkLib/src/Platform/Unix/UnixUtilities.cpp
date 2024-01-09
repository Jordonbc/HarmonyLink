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