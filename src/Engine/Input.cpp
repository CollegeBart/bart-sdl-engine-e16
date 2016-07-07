#include "Input.h"

Input::Input()
{
	memset(keys, 0, sizeof(bool) * SDL_NUM_SCANCODES);
	memset(lastKeys, 0, sizeof(bool) * SDL_NUM_SCANCODES);

	memset(mouseButtons, 0, sizeof(bool) * NUM_MOUSE_BUTTONS);
	memset(lastMouseButtons, 0, sizeof(bool) * NUM_MOUSE_BUTTONS);

	mousePosition = Point(0, 0);

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

	case SDL_JOYBUTTONDOWN:
		lastControllerButtons[(SDL_GameControllerButton)e.cbutton.button] = false;
		controllerButtons[(SDL_GameControllerButton)e.cbutton.button] = true;
		break;

	case SDL_JOYBUTTONUP:
		//lastControllerButtons[(SDL_GameControllerButton)e.cbutton.button] = true;
		lastControllerButtons[SDL_GameControllerGetButton(controller1, (SDL_GameControllerButton)e.cbutton.button)] = false;
		controllerButtons[(SDL_GameControllerButton)e.cbutton.button] = false;
		break;

	case SDL_JOYHATMOTION:
		if((SDL_GameControllerButton)e.jhat.value == 4)
		{
			if (!lastControllerButtons[12])
			{
				lastControllerButtons[12] = true;
			}
			else
			{
				lastControllerButtons[12] = false;
			}
		}
		if ((SDL_GameControllerButton)e.jhat.value == 2)
		{
			if (!lastControllerButtons[14])
			{
				lastControllerButtons[14] = true;
			}
			else
			{
				lastControllerButtons[14] = false;
			}
		}
		if ((SDL_GameControllerButton)e.jhat.value == 3)
		{
			if (!lastControllerButtons[11])
			{
				lastControllerButtons[11] = true;
			}
			else
			{
				lastControllerButtons[11] = false;
			}
		}
		if ((SDL_GameControllerButton)e.jhat.value == 1)
		{
			if (!lastControllerButtons[11])
			{
				lastControllerButtons[11] = true;
			}
			else
			{
				lastControllerButtons[11] = false;
			}
		}
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

bool Input::IsMouseButtonHeld(int button) const
{
	return mouseButtons[button - 1];
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

float Input::MouseX() const
{
	return mousePosition.x;
}

float Input::MouseY() const
{
	return mousePosition.y;
}

Point Input::GetMousePosition(Point& position) const
{
	// Calculer
	position = mousePosition;

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
