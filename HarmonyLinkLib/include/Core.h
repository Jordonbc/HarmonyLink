﻿// Copyright (c) 2024 Jordon Brooks
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
