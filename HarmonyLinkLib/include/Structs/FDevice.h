#pragma once

#include <HarmonyLinkStruct.h>

#include "Enums/EDevice.h"
#include "Enums/EPlatform.h"

namespace HarmonyLinkLib
{
    // Struct to represent a specific device with both platform and device type
    struct FDevice : HarmonyLinkStruct
    {
        EPlatform platform;
        EDevice device;
    };
}
