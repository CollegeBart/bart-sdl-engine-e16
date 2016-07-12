#pragma once

#include <iostream>
#include <vector>

class Component
{
	friend class Engine;

public:
	Component();
	virtual ~Component();
	void ReorderLastComp();
	virtual void Update();
	virtual void Draw();

private:
	static std::vector<Component*> components;
};

