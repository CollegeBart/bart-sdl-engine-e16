#include "TextBg.h"



TextBg::TextBg()
	: Sprite("TextBackground.png", 0, BOTTOM_POSITION, 0, 0, WIDTH, HEIGHT, 4)
{
	text = new Text(TEXT_X_OFFSET, 582, "ChronoTrigger.ttf", "Hello World!", 60);
	text->SetBgColor({ 0x00, 0x00, 0x00, 0x0 });
}


TextBg::~TextBg()
{
	delete text;
}

void TextBg::Update()
{
	text->SetPosition(TEXT_X_OFFSET, dstRect->y + TEXT_Y_OFFSET);

	if (gInput->IsKeyPressed(SDL_SCANCODE_X))
	{
		std::cout << "XXXXXXXXXXXXXXXX" << std::endl;

		if (dstRect->y == BOTTOM_POSITION)
		{
			SetPosition(0, 0);
		}
		else
		{
			SetPosition(0, BOTTOM_POSITION);
		}
	}
}


