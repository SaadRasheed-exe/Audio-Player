#include "InCarAudioPlayer.h"

InCarAudioPlayer::InCarAudioPlayer(std::string manu = "", std::string model = "") : AudioPlayer(manu, model)
{
    mounted = NULL;
    currentSong = Song();
    power = true;
}

bool InCarAudioPlayer::mount(StorageMedia* m)
{
    if (m->getFormat() == "ANY")
    {
        if (m->getCapacity() > 16)
        {
            std::cout << "USB's capacity must be 16 GBs or lesser." << std::endl;
            system("pause");
            return false;
        }
    }
    if (m->getCapacity() == -1)
    {
        if (m->getFormat() != "MP3")
        {
            std::cout << "CD's format must be MP3." << std::endl;
            system("pause");
            return false;
        }
    }
    mounted = m;
    if (power)
    {
        if (mounted->getList() != nullptr)
        {
            currentSong = *(mounted->getList());
            BASS_ChannelPlay(mounted->getList()->getChannel(), true);
        }
    }
    return true;
}

void InCarAudioPlayer::unmount()
{
    if (mounted)
    {
        BASS_ChannelStop(currentSong.getChannel());
        mounted = NULL;
        currentSong = Song();
    }
}

void InCarAudioPlayer::powerToggle()
{
    if (power)
    {
        BASS_ChannelPause(currentSong.getChannel());
    }
    else
    {
        if (mounted)
        {
            BASS_ChannelPlay(currentSong.getChannel(), false);
        }
    }
    power = !power;
}

StorageMedia* InCarAudioPlayer::getMounted() { return mounted; }

Song InCarAudioPlayer::getCurrSong() { return currentSong; }

bool InCarAudioPlayer::getPower() { return power; }

void InCarAudioPlayer::playNext()
{
    if (power && mounted)
    {
        for (size_t i = 0; i < mounted->getNoOfSongs() - 1; i++)
        {
            if (currentSong == mounted->getList()[i])
            {
                BASS_ChannelPlay(mounted->getList()[i + 1].getChannel(), true);
                currentSong = mounted->getList()[i + 1];
                return;
            }
        }
        currentSong = Song();
    }
}
