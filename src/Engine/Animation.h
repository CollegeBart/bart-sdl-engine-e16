#pragma once
#include "Sprite.h"


class Animation :
	public Sprite
{
public:

	/**
	* path, numFram, frameW and frameH are all included in defines, so:
	* Animation(DEFINE, x, y );
	* If frameRate is not specified, frameRate = 1
	* If isPlaying not specified, isPlaying = true
	**/
	Animation(const char* path,int numFrame,int frameW, int frameH, int x, int y);

	/**
	* path, numFram, frameW and frameH are all included in defines, so:
	* Animation(DEFINE, x, y, frameRate);
	* If frameRate is not specified, frameRate = 1
	* If isPlaying not specified, isPlaying = true
	**/
	Animation(const char* path, int numFrame, int frameW, int frameH, int x, int y, float frameRate);

	/**
	* path, numFram, frameW and frameH are all included in defines, so:
	* Animation(DEFINE, x, y, isPlaying);
	* If frameRate is not specified, frameRate = 1
	* If isPlaying not specified, isPlaying = true
	**/
	Animation(const char* path, int numFrame, int frameW, int frameH, int x, int y, bool isPlaying);

	/**
	* path, numFram, frameW and frameH are all included in defines, so:
	* Animation(DEFINE, x, y, frameRate, isPlaying);
	* If frameRate is not specified, frameRate = 1
	* If isPlaying not specified, isPlaying = true
	**/
	Animation(const char* path, int numFrame, int frameW, int frameH, int x, int y, float frameRate, bool isPlaying);

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
