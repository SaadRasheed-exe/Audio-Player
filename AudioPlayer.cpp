#include "AudioPlayer.h"

AudioPlayer::AudioPlayer(std::string manu, std::string model)
{
	manufacturer = manu;
	modelNumber = model;
}

std::string AudioPlayer::getManufacturer() const { return manufacturer; }

std::string AudioPlayer::getModel() const { return modelNumber; }