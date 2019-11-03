#pragma once

#include <SDL_mixer.h>
#include <string>

class Audio
{
private:

	~Audio();

	Mix_Music* music = nullptr;

	Mix_Chunk* effect = nullptr;
public:
	void loadMusic(const std::string& _path);

	void loadEffect(const std::string& _path);

	void play() const;
};
