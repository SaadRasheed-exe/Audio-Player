#include "CD.h"

CD::CD(int m, std::string f, std::string n) : StorageMedia(n)
{
    setMaxSongs(m);
    setFormat(f);
    numOfSongs = 0;
}

void CD::setFormat(std::string f)
{
    if (f == "MP3" || f == "WAV" || f == "PCM" || f == "AIFF")
    {
        format = f;
        return;
    }
    format = "MP3";
}

void CD::setMaxSongs(int n)
{
    if (n < 1)
    {
        maxSongs = 5;
        return;
    }
    maxSongs = n;
}

std::string CD::addMusic(Song &s)
{
    if (list == NULL)
    {
        list = new Song[1];
        list[0] = s;
        numOfSongs = 1;
        return "";
    }
    if (numOfSongs == maxSongs)
    {
        return "capacity";
    }
    if (s.getFormat() != tolower(format))
    {
        return "format";
    }
    for (int i = 0; i < numOfSongs; i++)
    {
        if (list[i].getTitle() == s.getTitle())
        {
            return "title";
        }
    }
    Song *temp = new Song[++numOfSongs];
    for (int i = 0; i < numOfSongs - 1; i++)
    {
        temp[i] = list[i];
    }
    delete[] list;
    list = temp;
    list[numOfSongs - 1] = s;
    return "";
}

std::string CD::getFormat() const { return format; }

int CD::getCapacity() const { return -1; }