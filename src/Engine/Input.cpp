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

void Input::Poll(const SDL_Event& e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		lastKeys[e.key.keysym.scancode] = false;
		keys[e.key.keysym.scancode] = true;
		break;

	case SDL_KEYUP:
		lastKeys[e.key.keysym.scancode] = true;
		keys[e.key.keysym.scancode] = false;
		break;

	case SDL_MOUSEMOTION:
		break;

	case SDL_MOUSEBUTTONDOWN:
		break;

	case SDL_MOUSEBUTTONUP:
		break;

	default:
		break;
	}
}

bool Input::IsKeyPressed(SDL_Scancode key)
{
	bool isPressed = !lastKeys[key] && keys[key];
	if (isPressed)
	{
		lastKeys[key] = keys[key];
	}
	return isPressed;
}

bool Input::IsKeyHeld(SDL_Scancode key) const
{
	return keys[key];
}

bool Input::IsKeyReleased(SDL_Scancode key)
{
	bool isReleased = lastKeys[key] && !keys[key];
	if (isReleased)
	{
		lastKeys[key] = keys[key];
	}
	return isReleased;
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

float Input::MouseX() const
{
	return 0.0f;
}

float Input::MouseY() const
{
	return 0.0f;
}

Point Input::GetMousePosition(Point& position) const
{
	// Calculer
	position.x = 0;
	position.y = 0;

	return position;
}
