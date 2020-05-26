#include "List.h"
#include <iostream>

List::List()
{
}
void List::add(Obstacles &obstacles)
{
	std::shared_ptr<ListEl> newEl = std::make_shared<ListEl>();
	newEl->obstacles = obstacles;
	if (head == nullptr)
	{
		head = newEl;
		
	}
	else
	{
		std::shared_ptr<ListEl> curr = head;
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = newEl;
	}
}
void List::remove(std::shared_ptr<ListEl> toBeDeleted)
{
	std::shared_ptr<ListEl> curr = head;
	if (head == toBeDeleted)
	{
		head = head->next;
	}
	else
	{
		while (curr->next != toBeDeleted)
		{
			curr = curr->next;
		}
		curr->next = toBeDeleted->next;
	}
}