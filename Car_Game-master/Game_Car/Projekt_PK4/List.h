#pragma once
#include "ListEl.h"

class List
{
public:
	std::shared_ptr<ListEl> head;
	List();
	void add(Obstacles &newEl);
	void remove(std::shared_ptr<ListEl> toBeDeleted);
};
