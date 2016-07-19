#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation()
	: Sprite()
{
}

SpriteAnimation::SpriteAnimation(const char * path, float x, float y, int srcX, int srcY, int srcW, int srcH, PlayMode playMode, float frameRate, float scale)
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

void SpriteAnimation::SetAnim(const char * path, SpriteInfo * spriteInfos, PlayMode playMode, float frameRate, int numFrame)
{
	this->SetTexture(path);
	for (int i = 0; i < numFrame+1; i++)
	{
		this->spriteInfos[i].h = spriteInfos[i].h;
		this->spriteInfos[i].w = spriteInfos[i].w;
		this->spriteInfos[i].srcH = spriteInfos[i].srcH;
		this->spriteInfos[i].srcW = spriteInfos[i].srcW;
		this->spriteInfos[i].srcX = spriteInfos[i].srcX;
		this->spriteInfos[i].srcY = spriteInfos[i].srcY;
		this->spriteInfos[i].scale = spriteInfos[i].scale;
		if (i == numFrame) {
			this->spriteInfos[i].scale = 0;
		}
	}
	this->playMode = playMode;
	this->frameRate = frameRate;
	this->Play();
}

const int SpriteAnimation::GetFrameRate()
{
	return frameRate;
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

			if (spriteInfos[currentFrame].scale == 0.0f)
			{
				if (playMode == LOOPING)
					currentFrame = -1;
				else
					Pause();
				return;
			}

			//SetSrcPosition(spriteInfos[currentFrame].srcX, spriteInfos[currentFrame].srcY);
			SetSrcRect(spriteInfos[currentFrame].srcX, spriteInfos[currentFrame].srcY, spriteInfos[currentFrame].srcH, spriteInfos[currentFrame].srcW);

			currentTime = 0;
		}
	}
}
