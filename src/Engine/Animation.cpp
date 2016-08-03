#include "Animation.h"



Animation::Animation(const char* path, int numFrame, int frameW, int frameH, int x, int y)
{
	SetDstRect(x, y, frameH, frameW);
	SetAnimation(path, numFrame, frameW, frameH);
}

Animation::Animation(const char * path, int numFrame, int frameW, int frameH, int x, int y, float frameRate)
{
	SetDstRect(x, y, frameH, frameW);
	SetAnimation(path, numFrame, frameW, frameH, frameRate);
}

Animation::Animation(const char * path, int numFrame, int frameW, int frameH, int x, int y, bool isPlaying)
{
	SetDstRect(x, y, frameH, frameW);
	SetAnimation(path, numFrame, frameW, frameH, isPlaying);
}

Animation::Animation(const char * path, int numFrame, int frameW, int frameH, int x, int y, float frameRate, bool isPlaying)
{
	SetDstRect(x, y, frameH, frameW);
	SetAnimation(path, numFrame, frameW, frameH, frameRate, isPlaying);
}

void Animation::SetAnimation(const char * path, int numFrame, int frameW, int frameH)
{
	SetTexture(path);
	SetDstRect(x, y, frameH, frameW);
	this->frameW = frameW;
	SetSrcRect(0, 0, frameH, frameW);
	this->numFrame = numFrame;
	frameRate = 1;
	Play();
}

void Animation::SetAnimation(const char * path, int numFrame, int frameW, int frameH, float frameRate)
{
	SetTexture(path);
	SetDstRect(x, y, frameH, frameW);
	this->frameW = frameW;
	SetSrcRect(0, 0, frameH, frameW);
	this->numFrame = numFrame;
	this->frameRate = frameRate;
	Play();
}

void Animation::SetAnimation(const char * path, int numFrame, int frameW, int frameH, bool isPlaying)
{
	SetTexture(path);
	SetDstRect(x, y, frameH, frameW);
	this->frameW = frameW;
	SetSrcRect(0, 0, frameH, frameW);
	this->numFrame = numFrame;
	frameRate = 1;
	this->isPlaying = isPlaying;
}

void Animation::SetAnimation(const char * path, int numFrame, int frameW, int frameH, float frameRate, bool isPlaying)
{
	SetTexture(path);
	SetDstRect(x, y, frameH, frameW);
	this->frameW = frameW;
	SetSrcRect(0, 0, frameH, frameW);
	this->numFrame = numFrame;
	this->frameRate = frameRate;
	this->isPlaying = isPlaying;
}

void Animation::Update()
{
	std::cout << "sup";
	if (isPlaying) {
		std::cout << "sup";
		timer -= gEngine->GetTimer()->GetDeltaTime()*frameRate;
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

const int Animation::GetFrame()
{
	return currentFrame;
}

