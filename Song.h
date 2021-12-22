#pragma once
#include <iostream>
#include "facilities.h"
#include "bass24/c/bass.h"

class Song
{
private:
    // Size in megabytes.
    double size;

    // Name of the song file.
    std::string fileName;

    // Gets the file size and stores it in size.
    void setSize();

    HSTREAM channel;

public:
    /// <summary>
    /// constructor
    /// </summary>
    /// <param name="">File Name</param>
    Song(std::string = "NULL");

    // Returns the song title.
    std::string getTitle();

    // Return the song size.
    double getSize();

    // Returns the format of the song.
    std::string getFormat();

    // Returns the file name.
    std::string getFileName();

    HSTREAM getChannel();

    bool operator==(Song&);

};

