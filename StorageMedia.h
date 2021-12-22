#pragma once
#include "Song.h"

class StorageMedia
{
protected:
    // The list of songs.
    Song* list;

    // Number of songs currently stored on the storage media.
    int numOfSongs;

    // Name of the storage media.
    std::string name;

public:
    /// <summary>
    /// Constructor
    /// </summary>
    /// <param name="Storage Media Name"></param>
    StorageMedia(std::string);

    // Destructor.
    ~StorageMedia();

    /// <summary>
    /// Adds music to the storage media.\n
    /// Returns "capacity" if storage media ran out of space.
    /// Returns "title" if the song with the same titles already exists.
    /// Returns "format" if the song format does not match the storage media format.
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual std::string addMusic(Song&) = 0;

    // Returns format of storage media.
    virtual std::string getFormat() = 0;

    // Returns capacity of storage media.
    virtual int getCapacity() = 0;

    // Returns the name of the storage media.
    std::string getName();

    // Returns the list of songs stored on the media.
    Song* getList();

    // Returns the number of songs stored on the media.
    int getNoOfSongs();
};
