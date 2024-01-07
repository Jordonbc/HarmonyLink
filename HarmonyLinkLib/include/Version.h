// Copyright (C) 2024  Jordon Brooks
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
