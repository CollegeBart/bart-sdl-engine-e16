#include "Wqt.h"
#include "Input.h"
Wqt::Wqt()
	: Sprite("wqt.jpg", 0, 0)
{

}

Wqt::~Wqt()
{

}

void Wqt::Update()
{
	if(gInput->IsKeyPressed(SDL_SCANCODE_SPACE))
	{
		std::cout << "SPACE!!! Pressed" << std::endl;
	}

	if (gInput->IsKeyHeld(SDL_SCANCODE_SPACE))
	{
		std::cout << "SPACE!!! Held" << std::endl;
	}

	if (gInput->IsKeyReleased(SDL_SCANCODE_SPACE))
	{
		std::cout << "SPACE!!! Released" << std::endl;
	}
}
