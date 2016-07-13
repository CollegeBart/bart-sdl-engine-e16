#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation()
	: Sprite()
{
}

SpriteAnimation::SpriteAnimation(const char * path, float x, float y, int srcX, int srcY, int srcW, int srcH, PlayMode playMode, int frameRate, float scale)
	: Sprite(path, x, y, srcX, srcY, srcW, srcH, scale)
{
}

SpriteAnimation::SpriteAnimation(const char* path, SpriteInfo* spriteInfos, PlayMode playMode, float frameRate)
	: Sprite(
		path, 
		spriteInfos[0].x, 
		spriteInfos[0].y, 
		spriteInfos[0].srcX, 
		spriteInfos[0].srcY, 
		spriteInfos[0].srcW, 
		spriteInfos[0].srcH, 
		spriteInfos[0].scale)
	, spriteInfos(spriteInfos)
	, frameRate(frameRate)
	, playMode(playMode)
	, currentFrame(0)
	, currentTime(0)
	, isplaying(true)
{

}

SpriteAnimation::~SpriteAnimation()
{
}

void SpriteAnimation::Play()
{
	currentFrame = 0;
	isplaying = true;
}

void SpriteAnimation::Pause()
{
	isplaying = false;
}

void SpriteAnimation::Update()
{
	if (isplaying)
	{
		currentTime += gEngine->deltaTime;

		if (currentTime >= 1.0f / frameRate)
		{
			currentFrame++;

			if (spriteInfos[currentFrame].scale == 0.f)
			{
				if (playMode == LOOPING)
					currentFrame = -1;
				else
					Pause();
				return;
			}

			SetSrcPosition(spriteInfos[currentFrame].srcX, spriteInfos[currentFrame].srcY);

			currentTime = 0;
		}
	}
}
