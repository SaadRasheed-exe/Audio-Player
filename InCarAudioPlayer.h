#pragma once
#include "AudioPlayer.h"
class InCarAudioPlayer :
    public AudioPlayer
{
private:
    // Mounted storage media. Is NULL if nothing is mounted.
    StorageMedia* mounted;

    // Current song being played on the player.
    Song currentSong;

    // Whether the audio player is powered on.
    bool power;

public:
    /// <summary>
    /// Constructor
    /// </summary>
    /// <param name="">Manufacturer</param>
    /// <param name="">Model Number</param>
    InCarAudioPlayer(std::string, std::string);

    // Mounts a storage media.
    bool mount(StorageMedia*);

    // Unmounts the mounted media.
    void unmount();

    // Returns mounted storage media.
    StorageMedia* getMounted();

    // Returns the current song being played.
    Song getCurrSong();

    // Toggles the power status of the audio player.
    void powerToggle();

    // Returns the power status of the player.
    bool getPower();

    void playNext();
};

