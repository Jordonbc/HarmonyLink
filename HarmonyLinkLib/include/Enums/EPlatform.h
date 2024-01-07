#pragma once

#include <cstdint>

// Enum class for representing different operating platforms
namespace HarmonyLinkLib
{
    enum class EPlatform : uint8_t
    {
        WINDOWS,
        LINUX,
        MAC,
        UNIX,
    };
}
