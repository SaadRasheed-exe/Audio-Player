#include "Song.h"
#include <fstream>
#include <direct.h>


using namespace std;

Song::Song(std::string f)
{
	fileName = f;
	if (f != "NULL")
	{
		/*string acd = "Hawayein - Arijit Singh.mp3";
		string narrow_string(acd);
		wstring wide_string = wstring(narrow_string.begin(), narrow_string.end());
		const wchar_t* result = wide_string.c_str();
		HSTREAM bhg = BASS_StreamCreateFile(false, result, 0, 0, 0);
		BASS_ChannelPlay(bhg, true);
		while (BASS_ChannelIsActive(bhg))
		{

		}*/
		string narrow_string(f);
		wstring wide_string = wstring(narrow_string.begin(), narrow_string.end());
		const wchar_t* result = wide_string.c_str();
		channel = BASS_StreamCreateFile(false, result, 0, 0, 0);
		/*BASS_ChannelPlay(channel, true);
		while (BASS_ChannelIsActive(channel))
		{

		}*/
		setSize();
	}
}

void Song::setSize()
{
	char buf[256];
	_getcwd(buf, 256);
	string c = buf;
	ifstream x(c + "\\" + fileName);
	x.seekg(0, ios::end);
	size = ((double)x.tellg() / (double)1024) / (double)1024;
}

double Song::getSize() { return size; }

std::string Song::getTitle()
{
	string c = "";
	for (int i = 0; i < fileName.length(); i++)
	{
		if (fileName[i] == '.')
		{
			break;
		}
		c += fileName[i];
	}
	return c;
}

std::string Song::getFormat()
{
	string c = "";
	for (int i = fileName.length() - 1; i > 0; i--)
	{
		if (fileName[i] == '.')
		{
			break;
		}
		c = fileName[i] + c;
	}
	return c;
}

std::string Song::getFileName() { return fileName; }

HSTREAM Song::getChannel() { return channel; }

bool Song::operator==(Song& s)
{
	if (fileName == s.fileName && channel == s.channel)
	{
		return true;
	}
	return false;
}