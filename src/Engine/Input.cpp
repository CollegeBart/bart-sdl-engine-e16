#include "Input.h"

Input::Input()
{
	memset(keys, 0, sizeof(bool) * SDL_NUM_SCANCODES);
	memset(lastKeys, 0, sizeof(bool) * SDL_NUM_SCANCODES);

	memset(mouseButtons, 0, sizeof(bool) * NUM_MOUSE_BUTTONS);
	memset(lastMouseButtons, 0, sizeof(bool) * NUM_MOUSE_BUTTONS);

	memset(lastControllerButtons, 0, sizeof(bool) * SDL_CONTROLLER_BUTTON_MAX);
	SDL_GameControllerAddMappingsFromFile("gamecontrollerdb.txt");
	OpenControllers();
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

bool Input::IsControllerButtonPressed(SDL_GameController* controller, SDL_GameControllerButton button)
{
	bool isPressed = false;
	if (!lastControllerButtons[button] && SDL_GameControllerGetButton(controller, button))
	{
		isPressed = true;
	}
	if (isPressed) 
	{
		lastControllerButtons[button] = true;
	}
	return isPressed;
}

bool Input::IsControllerButtonHeld(SDL_GameController* controller, SDL_GameControllerButton button) const
{
	return SDL_GameControllerGetButton(controller, button);
}

bool Input::IsControllerButtonReleased(SDL_GameController* controller, SDL_GameControllerButton button)
{
	bool isReleased = false;
	if (lastControllerButtons[button] && !SDL_GameControllerGetButton(controller, button))
	{
		isReleased = true;
	}
	if (isReleased)
	{
		lastControllerButtons[button] = false;
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

void Input::OpenControllers()
{
	/* Open available controllers. */
	for (int i = 0; i < 1; ++i) {
		if (controller1) {
			controller2 = SDL_GameControllerOpen(i);
			if (controller2) {
				std::cout << "Controller :" << SDL_GameControllerName(controller2) << "Connected as controller2!" << std::endl;
			}
		}
		if (!controller1) {
			controller1 = SDL_GameControllerOpen(i);
			if (controller1) {
				std::cout << "Controller :" << SDL_GameControllerName(controller1) << " Connected as controller1!" << std::endl;
			}
		}
		else {
			fprintf(stderr, "Could not open gamecontroller %i: %s\n    Did you add gamecontrollerdb.txt in your project file??", i, SDL_GetError());
		}
	}
}
