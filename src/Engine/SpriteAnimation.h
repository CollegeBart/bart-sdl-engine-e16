#pragma once

#include "Sprite.h"

#define LAST_FRAME { 0, 0, 0, 0, 0, 0, 0, 0, 0 }

/**
* Value goes: scale, x, y, w, h, srcX, srcY, srcW, srcH.
**/
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
		int srcY, int srcW, int srcH, PlayMode playMode, float frameRate, float scale = 1.0f);
	SpriteAnimation(const char* path, SpriteInfo* spriteInfo, PlayMode playMode, float frameRate);
	virtual ~SpriteAnimation();

	/**
	*Don't include LAST_FRAME in numFrame ... 
	*Initialize Sprite with Anim, This function only changes active animation and doesn't create a new one.
	**/
	void SetAnim(const char * path, SpriteInfo * spriteInfos, PlayMode playMode, float frameRate, int numFrame);
	const int GetFrameRate();
	void Play();
	void Pause();
	virtual void Update();

private:
	PlayMode playMode;
	bool isplaying;
	int frameRate;
	int currentFrame;
	float currentTime;
	SpriteInfo* spriteInfos;
};

