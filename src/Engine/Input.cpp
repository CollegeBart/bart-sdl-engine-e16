#include "Input.h"

Input::Input()
{
	memset(keys, 0, sizeof(bool) * SDL_NUM_SCANCODES);
	memset(lastKeys, 0, sizeof(bool) * SDL_NUM_SCANCODES);

	memset(mouseButtons, 0, sizeof(bool) * NUM_MOUSE_BUTTONS);
	memset(lastMouseButtons, 0, sizeof(bool) * NUM_MOUSE_BUTTONS);

	mousePosition = Point<int>(0, 0);

	ResetMouseScroll();

	memset(lastControllerButtons, 0, sizeof(bool) * SDL_CONTROLLER_BUTTON_MAX);
	memset(controllerButtons, 0, sizeof(bool) * SDL_CONTROLLER_BUTTON_MAX);
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
		mousePosition.x = e.motion.x;
		mousePosition.y = e.motion.y;
		break;

	case SDL_MOUSEBUTTONDOWN:
		//e.button.button = Number from 1 to 5, -1 to get the array index
		lastMouseButtons[e.button.button - 1] = false;
		mouseButtons[e.button.button - 1] = true;
		break;

	case SDL_MOUSEBUTTONUP:
		lastMouseButtons[e.button.button - 1] = true;
		mouseButtons[e.button.button - 1] = false;
		break;

	case SDL_MOUSEWHEEL:
		mouseScrollDirection = e.wheel.y;
		break;

	case SDL_CONTROLLERBUTTONDOWN:
		lastControllerButtons[e.cbutton.button] = false;
		controllerButtons[e.cbutton.button] = true;
		break;

	case SDL_CONTROLLERBUTTONUP:
		lastControllerButtons[e.cbutton.button] = true;
		controllerButtons[e.cbutton.button] = false;
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
	bool isPressed = !lastControllerButtons[button] && controllerButtons[button];
	if (isPressed) 
	{
		lastControllerButtons[button] = controllerButtons[button];
	}
	return isPressed;
}

bool Input::IsControllerButtonReleased(SDL_GameController* controller, SDL_GameControllerButton button)
{
	bool isReleased = lastControllerButtons[button] && !controllerButtons[button];
	if (isReleased)
	{
		lastControllerButtons[button] = controllerButtons[button];
	}
	return isReleased;
}


bool Input::IsMouseButtonPressed(int button)
{
	//e.button.button = Number from 1 to 5, -1 to get the array index
	bool isPressed = !lastMouseButtons[button-1] && mouseButtons[button-1];
	if (isPressed)
	{
		lastMouseButtons[button - 1] = mouseButtons[button - 1];
	}
	return isPressed;
}

bool Input::IsMouseButtonReleased(int button)
{
	bool isReleased = lastMouseButtons[button - 1] && !mouseButtons[button - 1];
	if (isReleased)
	{
		lastMouseButtons[button - 1] = mouseButtons[button - 1];
	}
	return isReleased;
}

void Input::OpenControllers()
{
	/* Open available controllers. */
	for (int i = 0; i < SDL_NumJoysticks(); ++i) {
		if (controller1) {
			controller2 = SDL_GameControllerOpen(i);
			if (controller2) {
				std::cout << "Controller :" << SDL_GameControllerName(controller2) << "Connected as controller2!" << std::endl;
			}
			else {
				fprintf(stderr, "Could not open gamecontroller %i: %s\nDid you add gamecontrollerdb.txt in your project file??\n Pick it up in TestEnvironement files", i, SDL_GetError());
			}
		}
		if (!controller1) {
			controller1 = SDL_GameControllerOpen(i);
			if (controller1) {
				std::cout << "Controller :" << SDL_GameControllerName(controller1) << " Connected as controller1!" << std::endl;
			}
			else {
				fprintf(stderr, "Could not open gamecontroller %i: %s\nDid you add gamecontrollerdb.txt in your project file??\n Pick it up in TestEnvironement files", i, SDL_GetError());
			}
		}
	}
}
