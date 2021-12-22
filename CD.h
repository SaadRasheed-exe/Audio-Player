#pragma once
#include "StorageMedia.h"

class CD :
    public StorageMedia
{
private:
    // Format of the songs on the CD.
    std::string format;

    // Maximum number of songs CD can store.
    int maxSongs;

    // Sets the format of the CD.
    void setFormat(std::string);

    // Sets the max number of songs on the CD.
    void setMaxSongs(int);

public:
    /// <summary>
    /// Constructor
    /// </summary>
    /// <param name="">Max number of songs CD can store.</param>
    /// <param name="">Format of the songs CD can store.</param>
    /// <param name="">Name of the CD.</param>
    CD(int = 5, std::string = "MP3", std::string = "Maxell RW CD");

    // Adds music to the CD.
    std::string addMusic(Song&);

    // Returns format of songs in the CD.
    std::string getFormat();

    int getCapacity();
};

