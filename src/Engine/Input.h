#pragma once

#include "SDL.h"
#include "Component.h"
#include "Point.h"

#define NUM_MOUSE_BUTTONS 5
#define CONTROLLER_JOYSTICK_DEATHZONE 8000

class Input
{
public:
	Input();
	~Input();

	void Poll(const SDL_Event& e);
	//Keyboard events
	bool IsKeyPressed(SDL_Scancode key);
	bool IsKeyHeld(SDL_Scancode key) const { return keys[key]; }
	bool IsKeyReleased(SDL_Scancode key);

	//Controller support
	SDL_GameController *controller1 = nullptr;
	SDL_GameController *controller2 = nullptr;
	bool IsControllerButtonPressed(SDL_GameController* controller, SDL_GameControllerButton button);
	bool IsControllerButtonHeld(SDL_GameController* controller, SDL_GameControllerButton button) const { return SDL_GameControllerGetButton(controller, button); }
	bool IsControllerButtonReleased(SDL_GameController* controller, SDL_GameControllerButton button);

	//Mouse events
	bool IsMouseButtonPressed(int button);
	bool IsMouseButtonHeld(int button) const { return mouseButtons[button - 1]; }
	bool IsMouseButtonReleased(int button);
	bool IsMouseWheelScrolling() const{ return mouseScrollDirection != 0.0f; }
	float MouseX() const { return mousePosition.x; }
	float MouseY() const { return mousePosition.y; }
	Point<int> GetMousePosition(Point<int>& position) const { position = mousePosition; return position; }
	float GetMouseScroll() const { return mouseScrollDirection; }
	void ResetMouseScroll() { mouseScrollDirection = 0.0f; }

private:
	bool keys[SDL_NUM_SCANCODES];
	bool lastKeys[SDL_NUM_SCANCODES];

	bool lastControllerButtons[SDL_CONTROLLER_BUTTON_MAX];
	bool controllerButtons[SDL_CONTROLLER_BUTTON_MAX];
	void OpenControllers();

	bool mouseButtons[NUM_MOUSE_BUTTONS];
	bool lastMouseButtons[NUM_MOUSE_BUTTONS];

	float mouseScrollDirection;

	//Might need SDL_MouseMotionEvent instead
	Point<int> mousePosition;
};

