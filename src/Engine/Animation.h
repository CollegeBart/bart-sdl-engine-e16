#pragma once
#include "Sprite.h"
class Animation :
	public Sprite
{
public:
	Animation(const char* path,int x, int y,int numFrame,int frameW, int frameH);
	Animation(const char* path,int x, int y, int numFrame, int frameW, int frameH, float frameRate);
	Animation(const char* path, int x, int y, int numFrame, int frameW, int frameH, bool isPlaying);
	Animation(const char* path, int x, int y, int numFrame, int frameW, int frameH, float frameRate, bool isPlaying);
	void Update();
	~Animation();
	void SetCurrentFrame(int frame);
	void Play();
	void Stop();
private:
	int frameW;
	int numFrame;
	bool isPlaying;
	int currentFrame = 0;
	float frameRate;
	float timer = 1;
};

