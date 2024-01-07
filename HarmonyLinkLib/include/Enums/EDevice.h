#pragma once

#include <cstdint>

// Enum class for representing different types of devices
namespace HarmonyLinkLib
{
    enum class EDevice : uint8_t
    {
        DESKTOP,
        LAPTOP,
        HANDHELD,
    
        STEAM_DECK,
        // ROG_ALLY
        // AYONEO_SLIDE
        // etc...
    };
}
