#pragma once
#include "StorageMedia.h"

class USB :
    public StorageMedia
{
private:
    // Capacity of the USB in gigabytes.
    int capacity;

    // Sets the capacity of the USB if its in the power of 2.
    void setCap(int);

public:
    /// <summary>
    /// Constructor
    /// </summary>
    /// <param name="">Size of USB in gigabytes.</param>
    /// <param name="">Name of the USB.</param>
    USB(int = 4, std::string = "SanDisk USB");

    // Adds music to the USB.
    std::string addMusic(Song&);

    // Returns format of songs on the USB.
    std::string getFormat();

    // Returns capacity of the USB.
    int getCapacity();
};

