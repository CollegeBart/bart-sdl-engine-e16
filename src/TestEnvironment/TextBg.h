#pragma once
#include "Sprite.h"
#include "Text.h"

#define WIDTH 255
#define HEIGHT 75
#define X_POS 275
#define BOTTOM_POSITION 565
#define TEXT_Y_OFFSET 17
#define TEXT_X_OFFSET 32

class TextBg :
	public Sprite
{
public:
	TextBg();
	~TextBg();
	void Update();
private:
	Text * text;
};

