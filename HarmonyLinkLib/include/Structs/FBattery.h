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
