#pragma once

#include <cstdint>
#include <unordered_set>
#include "FString.h"

#include "HarmonyLinkStruct.h"

namespace HarmonyLinkLib
{
    struct FCPUInfo : HarmonyLinkStruct
    {
        FString VendorID;
        FString Model_Name;
        uint32_t Physical_Cores = 0;
        uint32_t Logical_Cores = 0;
        std::unordered_set<FString> Flags;

        void print() const
        {
            wprintf(L"VendorID: '%hs'\n", VendorID.c_str());
            wprintf(L"Model_Name: '%hs'\n", Model_Name.c_str());
            wprintf(L"Physical_Cores: '%d'\n", Physical_Cores);
            wprintf(L"Logical_Cores: '%d'\n", Logical_Cores);
            
            // Initialize a string to hold all flags
            std::string allFlags;
            for (const auto& flag : Flags) {
                allFlags += std::string(flag.c_str()) + " "; // Append each flag followed by a space
            }

            // Remove the trailing space
            if (!allFlags.empty()) {
                allFlags.pop_back();
            }

            wprintf(L"Flags: '%hs'\n", allFlags.c_str());
        }
    };
}
