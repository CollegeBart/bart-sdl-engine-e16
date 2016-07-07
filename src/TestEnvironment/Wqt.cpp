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

#pragma region MouseTests
	if (gInput->IsMouseButtonPressed(SDL_BUTTON_LEFT))
	{
		std::cout << "Left mouse button click at coordinates (" << gInput->MouseX() << ", " << gInput->MouseY() << ")!" << std::endl;
	}
	if (gInput->IsMouseButtonPressed(SDL_BUTTON_RIGHT))
	{
		std::cout << "Right mouse button click at coordinates (" << gInput->MouseX() << ", " << gInput->MouseY() << ")!" << std::endl;
	}
	if (gInput->IsMouseButtonPressed(SDL_BUTTON_MIDDLE))
	{
		std::cout << "Middle mouse button click at coordinates (" << gInput->MouseX() << ", " << gInput->MouseY() << ")!" << std::endl;
	}
	/* //Is not fully tested
	if (gInput->IsMouseButtonPressed(SDL_BUTTON_X1))
	{
		std::cout << "Side button 1 click!" << std::endl;
	}
	if (gInput->IsMouseButtonPressed(SDL_BUTTON_X2))
	{
		std::cout << "Side button 2 click!" << std::endl;
	}*/

	if (gInput->IsMouseButtonHeld(SDL_BUTTON_LEFT))
	{
		std::cout << "Left mouse button hold!" << std::endl;
	}
	if (gInput->IsMouseButtonHeld(SDL_BUTTON_RIGHT))
	{
		std::cout << "Right mouse button hold!" << std::endl;
	}
	if (gInput->IsMouseButtonHeld(SDL_BUTTON_MIDDLE))
	{
		std::cout << "Middle mouse button hold!" << std::endl;
	}
	/* //Is not fully tested
	if (gInput->IsMouseButtonHeld(SDL_BUTTON_X1))
	{
	std::cout << "Side button 1 hold!" << std::endl;
	}
	if (gInput->IsMouseButtonHeld(SDL_BUTTON_X2))
	{
	std::cout << "Side button 2 hold!" << std::endl;
	}*/

	if (gInput->IsMouseButtonReleased(SDL_BUTTON_LEFT))
	{
		std::cout << "Left mouse button release!" << std::endl;
	}
	if (gInput->IsMouseButtonReleased(SDL_BUTTON_RIGHT))
	{
		std::cout << "Right mouse button release!" << std::endl;
	}
	if (gInput->IsMouseButtonReleased(SDL_BUTTON_MIDDLE))
	{
		std::cout << "Middle mouse button release!" << std::endl;
	}
	/* //Is not fully tested
	if (gInput->IsMouseButtonReleased(SDL_BUTTON_X1))
	{
	std::cout << "Side button 1 release!" << std::endl;
	}
	if (gInput->IsMouseButtonReleased(SDL_BUTTON_X2))
	{
	std::cout << "Side button 2 release!" << std::endl;
	}*/
#pragma endregion
}
