// Copyright (C) 2024  Jordon Brooks

#pragma once

#include <memory>
#include <cstring>
#include <string>

#include "Core.h"  // Replace with actual API export macro

/**
 * @file FString.h
 * @brief FString Class - Custom String Management for DLL Export
 *
 * The FString class is a custom string management class designed to safely encapsulate
 * string handling and memory management, especially for use in DLLs (Dynamic Link Libraries).
 * It resolves the common issue of exporting classes containing standard library types,
 * such as std::string, across DLL boundaries, which can lead to compiler warnings or errors.
 *
 * Features:
 * - Implements basic string operations such as construction, destruction, copy, and move semantics.
 * - Utilizes smart pointers (std::unique_ptr) for automatic memory management, reducing the risk of memory leaks.
 * - Provides a simple interface for interacting with character strings, similar to std::string.
 * - Includes both deep copy semantics for safety and move semantics for performance in object transfers.
 *
 * Usage:
 * FString can be used as a safer alternative to std::string for classes that are exported from a DLL.
 * It handles memory allocation/deallocation automatically and provides a basic set of string operations.
 * 
 * Example:
 *     FString myString("Hello, world!");
 *     std::cout << myString.c_str() << std::endl; // Output: Hello, world!
 *
 * Note:
 * - The class is currently designed with basic functionality. Additional features such as
 *   string concatenation, substring, and comparison operations can be added as needed.
 * - Ensure that the HarmonyLinkLibApi.h (or equivalent) file correctly defines the export macro
 *   for DLL usage.
 *
 */
 namespace HarmonyLinkLib
 {
    class HARMONYLINKLIB_API FString {
    public:
        FString() : data_(new char[1]) {
            data_[0] = '\0';
        }

        FString(const char* str) {
            const size_t len = strlen(str);
            data_ = new char[len + 1];
            memcpy(data_, str, len + 1);
        }

        // Copy constructor
        FString(const FString& other) {
            const size_t len = strlen(other.data_);
            data_ = new char[len + 1];
            memcpy(data_, other.data_, len + 1);
        }

        ~FString() {
            delete[] data_;
        }

        // Copy assignment operator
        FString& operator=(const FString& other) {
            if (this != &other) {
                delete[] data_;
                const size_t len = strlen(other.data_);
                data_ = new char[len + 1];
                memcpy(data_, other.data_, len + 1);
            }
            return *this;
        }

        // Concatenation operator for FString objects
        FString operator+(const FString& other) const {
            size_t thisLen = strlen(this->data_);
            size_t otherLen = strlen(other.data_);
            char* concatenated = new char[thisLen + otherLen + 1];

            memcpy(concatenated, this->data_, thisLen);
            memcpy(concatenated + thisLen, other.data_, otherLen + 1);

            FString result(concatenated);
            delete[] concatenated;
            return result;
        }

        // Concatenation operator for const char* 
        FString operator+(const char* other) const {
            return *this + FString(other);
        }

        // Friend function to allow concatenation with const char* on the left-hand side
        friend FString operator+(const char* lhs, const FString& rhs) {
            return FString(lhs) + rhs;
        }

        // Move constructor
        FString(FString&& other) noexcept : data_(other.data_) {
            other.data_ = nullptr;
        }

        FString(const std::string& str) {
            const size_t len = str.length();
            data_ = new char[len + 1];
            memcpy(data_, str.c_str(), len + 1);
        }

        // Move assignment operator
        FString& operator=(FString&& other) noexcept {
            if (this != &other) {
                delete[] data_;
                data_ = other.data_;
                other.data_ = nullptr;
            }
            return *this;
        }

        bool operator==(const FString& other) const {
            return strcmp(data_, other.data_) == 0;
        }

        // Method to get a lowercase version of the string
        static FString to_lower(FString& from)
        {
            for (size_t i = 0; i < strlen(from.data_); ++i) {
                from.data_[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(from.data_[i])));
            }
            return from;
        }

        // Overloaded static method to handle const char*
        static FString to_lower(const char* from) {
            FString temp_string(from); // Create an FString from const char*
            return to_lower(temp_string); // Reuse the existing to_lower method
        }

        const char* c_str() const {
            return data_;
        }

    private:
        char* data_ = nullptr;
    };
 }

namespace std {
    template<>
    struct hash<HarmonyLinkLib::FString> {
        size_t operator()(const HarmonyLinkLib::FString& s) const {
            size_t hashValue = 5381;  // Starting value recommended by the djb2 algorithm
            const char* str = s.c_str();

            for (size_t i = 0; str[i] != '\0'; ++i) {
                hashValue = ((hashValue << 5) + hashValue) + static_cast<unsigned char>(str[i]);
                // Equivalent to hashValue * 33 + str[i]
            }

            return hashValue;
        }
    };
}
