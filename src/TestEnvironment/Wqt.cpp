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
	if (gInput->IsControllerButtonPressed(gInput->controller1, SDL_CONTROLLER_BUTTON_A)) {
		std::cout << "A" << std::endl;
	}
	if (gInput->IsControllerButtonPressed(gInput->controller1, SDL_CONTROLLER_BUTTON_B)) {
		std::cout << "B" << std::endl;
	}

	if (gInput->IsControllerButtonPressed(gInput->controller1, SDL_CONTROLLER_BUTTON_X)) {
		std::cout << "X" << std::endl;
	}

	if (gInput->IsControllerButtonPressed(gInput->controller1, SDL_CONTROLLER_BUTTON_Y)) {
		std::cout << "Y" << std::endl;
	}

	if (gInput->IsControllerButtonPressed(gInput->controller1, SDL_CONTROLLER_BUTTON_DPAD_UP)) {
		std::cout << "UP" << std::endl;
	}
	if (gInput->IsControllerButtonPressed(gInput->controller1, SDL_CONTROLLER_BUTTON_DPAD_DOWN)) {
		std::cout << "DOWN" << std::endl;
	}
	if (gInput->IsControllerButtonPressed(gInput->controller1, SDL_CONTROLLER_BUTTON_DPAD_LEFT)) {
		std::cout << "LEFT" << std::endl;
	}
	if (gInput->IsControllerButtonPressed(gInput->controller1, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)) {
		std::cout << "RIGHT" << std::endl;
	}



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
