#pragma once

#include "SDL.h"
#include "Component.h"
#include "Point.h"

#define NUM_MOUSE_BUTTONS 5

class Input :
	public Component
{
public:
	Input();
	~Input();

	void Update();

	bool IsPressed(SDL_Scancode key) const;
	bool IsHeld(SDL_Scancode key) const;
	bool IsReleased(SDL_Scancode key) const;

	bool IsMouseButtonPressed(int button) const;
	bool IsMouseButtonHeld(int button) const;
	bool IsMouseButtonReleased(int button) const;

	Point GetMousePosition(Point& position) const;

private:
	bool keys[SDL_NUM_SCANCODES];
	bool lastKeys[SDL_NUM_SCANCODES];

	bool mouseButtons[NUM_MOUSE_BUTTONS];
	bool lastMouseButtons[NUM_MOUSE_BUTTONS];
};

