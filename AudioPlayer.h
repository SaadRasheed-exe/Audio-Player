#pragma once
#include "CD.h"
#include "USB.h"

class AudioPlayer
{
protected:
    // Manufacturer of the Audio Player.
    std::string manufacturer;

    // Model number of the Audio Player.
    std::string modelNumber;

public:
    /// <summary>
    /// Constructor
    /// </summary>
    /// <param name="">Manufacturer</param>
    /// <param name="">Model Number</param>
    AudioPlayer(std::string, std::string);

    // Returns manufacturer's name.
    std::string getManufacturer() const;

    // Returns model number.
    std::string getModel();
};

