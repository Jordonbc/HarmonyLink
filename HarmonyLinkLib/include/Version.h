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

#include "Core.h"
#include <Version.generated.h>

#include "FString.h"

namespace HarmonyLinkLib
{
    class HARMONYLINKLIB_API version
    {
    public:
        version() = default;
    
        static FString ToString()
        {
            return HARMONYLINK_VERSION;
        }

        static FString get_build_timestamp()
        {
            return {__TIMESTAMP__};
        }

        static FString get_git_branch()
        {
            return {GIT_BRANCH_NAME};
        }

        static FString get_git_commit_timestamp()
        {
            return {GIT_COMMIT_TIMESTAMP};
        }

        static bool is_debug()
        {
#ifdef DEBUG_MODE
            return true;
#else
            return false;
#endif
        }
    };
}
