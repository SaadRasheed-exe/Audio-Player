#include "StorageMedia.h"

StorageMedia::StorageMedia(std::string n)
{
	name = n;
	list = NULL;
	numOfSongs = 0;
}

StorageMedia::~StorageMedia()
{
	if (list)
	{
		delete[] list;
	}
}

std::string StorageMedia::getName() const { return name; }

Song *StorageMedia::getList() const { return list; }

int StorageMedia::getNoOfSongs() const { return numOfSongs; }