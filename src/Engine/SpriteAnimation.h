#pragma once

#include "Sprite.h"

class SpriteAnimation :
	public Sprite
{
public:
	enum PlayMode { LOOPING, PING_PONG, CLAMP, REVERSE};

	SpriteAnimation();
	//SpriteAnimation();
	virtual ~SpriteAnimation();

	void Play();
	void Pause();
	void Update();

private:

	bool isplaying, isLooping;
	int frameRate, currentFrame;
	float currentTime;

};

