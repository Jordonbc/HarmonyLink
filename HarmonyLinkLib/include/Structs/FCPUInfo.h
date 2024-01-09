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
