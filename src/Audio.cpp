#include "Audio.h"

Audio::~Audio()
{
	Mix_FreeMusic(music);
	Mix_FreeChunk(effect);
	music = nullptr;
	effect = nullptr;
}

void Audio::loadMusic(const std::string& _path)
{
	music = Mix_LoadMUS(_path.c_str());
	if (music == nullptr)
	{
		printf("Music file failed to load!");
		throw std::exception(Mix_GetError());
	}
}

void Audio::loadEffect(const std::string& _path)
{
	effect = Mix_LoadWAV(_path.c_str());
	if (effect == nullptr)
	{
		printf("Sound Effect file failed to load!");
		throw std::exception(Mix_GetError());
	}
}

void Audio::play() const
{
	if (music != nullptr || effect != nullptr)
	{
		if (music != nullptr)
			Mix_PlayMusic(music, -1);
		if (effect != nullptr)
			Mix_PlayChannel(-1, effect, 0);
	}
	else { throw std::exception("Sound Effect was not applied to this Audio instance!"); }
}
