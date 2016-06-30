#pragma once

#define FOREACH_COMPONENT(x)					\
{												\
	std::vector<Component*>::iterator iter		\
		= Component::components.begin();		\
	while (iter != Component::components.end())	\
	{											\
		(*iter)->x;								\
		iter++;									\
	}											\
}