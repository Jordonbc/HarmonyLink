#pragma once

struct HarmonyLinkStruct
{
    // Virtual destructor is important for proper cleanup of derived types
    virtual ~HarmonyLinkStruct() = default;

    // Method to deallocate the object
    void free() const
    {
        delete this;
    }
};
