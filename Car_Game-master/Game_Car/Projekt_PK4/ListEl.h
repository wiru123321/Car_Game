#pragma once
#include "Obstacles.h"
#include <memory>
class ListEl
{
public:
	Obstacles obstacles;
	std::shared_ptr<ListEl> next;
};
