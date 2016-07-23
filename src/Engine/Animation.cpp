#include "Animation.h"



Animation::Animation(const char* path, int numFrame, int frameW , int frameH,int x, int y)
{
	SetTexture(path);
	this->SetDstRect(x, y, frameH, frameW);
	this->frameW = frameW;
	this->SetSrcRect(0, 0, frameH, frameW);
	this->numFrame = numFrame;
	frameRate = 1;
	Play();
}

Animation::Animation(const char * path, int numFrame, int frameW, int frameH, int x, int y, float frameRate)
{
	SetTexture(path);
	this->SetDstRect(x, y, frameH, frameW);
	this->frameW = frameW;
	this->SetSrcRect(0, 0, frameH, frameW);
	this->numFrame = numFrame;
	this->frameRate = frameRate;
	Play();

}

Animation::Animation(const char * path, int numFrame, int frameW, int frameH, int x, int y, bool isPlaying)
{
	SetTexture(path);
	this->SetDstRect(x, y, frameH, frameW);
	this->frameW = frameW;
	this->SetSrcRect(0, 0, frameH, frameW);
	this->numFrame = numFrame;
	frameRate = 1;
	this->isPlaying = isPlaying;
}

Animation::Animation(const char * path, int numFrame, int frameW, int frameH, int x, int y, float frameRate, bool isPlaying)
{
	SetTexture(path);
	this->SetDstRect(x, y, frameH, frameW);
	this->frameW = frameW;
	this->SetSrcRect(0, 0, frameH, frameW);
	this->numFrame = numFrame;
	this->frameRate = frameRate;
	this->isPlaying = isPlaying;
}

void Animation::Update()
{
	if (isPlaying) {
		timer -= gEngine->deltaTime*frameRate;
		if (timer <= 0)
		{
			if (currentFrame < numFrame-1)
			{
				currentFrame++;
			}
			else
			{
				currentFrame = 0;
			}
			timer = 1;
		}
	}
		srcX = frameW * currentFrame;
}


Animation::~Animation()
{
}

void Animation::SetCurrentFrame(int frame)
{
	currentFrame = frame;
}

void Animation::Play()
{
	isPlaying = true;
}

void Animation::Stop()
{
	isPlaying = false;
}

