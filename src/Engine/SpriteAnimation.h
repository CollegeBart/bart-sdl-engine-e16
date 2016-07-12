#pragma once

#include "Sprite.h"

#define LAST_FRAME { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0 }

struct SpriteInfo
{
	float scale;
	int x, y, w, h, srcX, srcY, srcW, srcH;
};

class SpriteAnimation :
	public Sprite
{
public:
	enum PlayMode { LOOPING, RLOOPING, PING_PONG, CLAMP, REVERSE};

	SpriteAnimation();
	SpriteAnimation(const char* path, float x, float y, int srcX,
		int srcY, int srcW, int srcH, PlayMode playMode, int frameRate, float scale = 1.0f);
	SpriteAnimation(const char* path, SpriteInfo* spriteInfo, PlayMode playMode, float frameRate);
	virtual ~SpriteAnimation();

	void Play();
	void Pause();
	void Update();

private:
	bool isplaying;
	int frameRate, currentFrame;
	float currentTime;
	PlayMode playMode;
	SpriteInfo* spriteInfos;
};

