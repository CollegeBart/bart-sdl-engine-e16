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

	bool IsKeyPressed(SDL_Scancode key);
	bool IsKeyHeld(SDL_Scancode key) const;
	bool IsKeyReleased(SDL_Scancode key);

	bool IsControllerButtonPressed(SDL_GameControllerButton button);
	bool IsControllerButtonHeld(SDL_GameControllerButton button) const;
	bool IsControllerButtonReleased(SDL_GameControllerButton button);

	bool IsMouseButtonPressed(int button) const;
	bool IsMouseButtonHeld(int button) const;
	bool IsMouseButtonReleased(int button) const;

	float MouseX() const;
	float MouseY() const;

	Point GetMousePosition(Point& position) const;

private:
	bool keys[SDL_NUM_SCANCODES];
	bool lastKeys[SDL_NUM_SCANCODES];

	SDL_GameController *controller = nullptr;
	int lastControllerButtons = 15;
	void OpenControllers();

	bool mouseButtons[NUM_MOUSE_BUTTONS];
	bool lastMouseButtons[NUM_MOUSE_BUTTONS];
};

