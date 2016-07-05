#include "Input.h"

Input::Input()
{
	memset(keys, 0, sizeof(bool) * SDL_NUM_SCANCODES);
	memset(lastKeys, 0, sizeof(bool) * SDL_NUM_SCANCODES);

	memset(mouseButtons, 0, sizeof(bool) * NUM_MOUSE_BUTTONS);
	memset(lastMouseButtons, 0, sizeof(bool) * NUM_MOUSE_BUTTONS);
}

Input::~Input()
{

}

void Input::Update()
{
	std::cout << "Input::Update" << std::endl;
}

bool Input::IsPressed(SDL_Scancode key) const
{
	return false;
}

bool Input::IsHeld(SDL_Scancode key) const
{
	return false;
}

bool Input::IsReleased(SDL_Scancode key) const
{
	return false;
}

bool Input::IsMouseButtonPressed(int button) const
{
	return false;
}

bool Input::IsMouseButtonHeld(int button) const
{
	return false;
}

bool Input::IsMouseButtonReleased(int button) const
{
	return false;
}

Point Input::GetMousePosition(Point& position) const
{
	// Calculer
	position.x = 0;
	position.y = 0;

	return p;
}
