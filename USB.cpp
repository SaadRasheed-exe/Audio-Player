#include "USB.h"
#include "facilities.h"

USB::USB(int c, std::string n) : StorageMedia(n)
{
    setCap(c);
}

void USB::setCap(int c)
{
    if (isPowerOf(c, 2))
    {
        capacity = c;
    }
    else
    {
        capacity = 4;
    }
}

std::string USB::addMusic(Song &s)
{
    if (list == NULL)
    {
        list = new Song[1];
        list[0] = s;
        numOfSongs = 1;
        return "";
    }
    double totalsize = 0;
    for (int i = 0; i < numOfSongs; i++)
    {
        if (list[i].getTitle() == s.getTitle())
        {
            return "title";
        }
        totalsize += list[i].getSize();
    }
    if (totalsize > capacity * 1024)
    {
        return "capacity";
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

std::string USB::getFormat() const { return "ANY"; }

int USB::getCapacity() const { return capacity; }