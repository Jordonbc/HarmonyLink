// Copyright (C) 2023  Jordon Brooks

#pragma once

// Use a preprocessor definition to switch between export and import declarations
#ifdef _WIN32
    #ifdef HARMONYLINKLIB_EXPORTS
        #define HARMONYLINKLIB_API __declspec(dllexport)
    #else
        #define HARMONYLINKLIB_API __declspec(dllimport)
    #endif
#else
    #define HARMONYLINKLIB_API
#endif
