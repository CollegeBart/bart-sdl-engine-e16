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
	
	void SetAnimation(const char* path, int numFrame, int frameW, int frameH);
	void SetAnimation(const char* path, int numFrame, int frameW, int frameH, float frameRate);
	void SetAnimation(const char* path, int numFrame, int frameW, int frameH, bool isPlaying);
	void SetAnimation(const char* path, int numFrame, int frameW, int frameH, float frameRate, bool isPlaying);
	virtual void Update();
	virtual ~Animation();
	void SetCurrentFrame(int frame);
	void Play();
	void Stop();
	const int GetFrame();
private:
	int frameW;
	int numFrame;
	bool isPlaying;
	int currentFrame = 0;
	float frameRate;
	float timer = 1;
};

