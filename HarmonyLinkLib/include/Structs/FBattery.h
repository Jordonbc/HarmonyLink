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

#pragma once

#include <cstdint>
#include <iostream>

#include "HarmonyLinkStruct.h"

namespace HarmonyLinkLib
{
    struct FBattery : HarmonyLinkStruct
    {
        bool has_battery;
        bool is_connected_to_ac;
        uint8_t battery_percent;

        void to_string() const {
            std::wcout << "Battery present: " << (has_battery ? "'Yes'" : "'No'") << '\n';
            std::wcout << "Connected to AC: " << (is_connected_to_ac ? "'Yes'" : "'No'") << '\n';
            std::wcout << "Battery percent: '" << static_cast<int>(battery_percent) << "%'" << '\n';
        }
    };
}
