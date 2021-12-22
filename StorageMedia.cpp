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

std::string StorageMedia::getName()
{
	return name;
}

Song* StorageMedia::getList()
{
	return list;
}

int StorageMedia::getNoOfSongs()
{
	return numOfSongs;
}