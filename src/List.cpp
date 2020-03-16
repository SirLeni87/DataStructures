/*
 * ListElem.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: Tomasz
 */

#include "List.h"
#include <iostream>

List::List()
{
	head = nullptr;
	tail = nullptr;
}

List::~List()
{
	while(head != nullptr)
	{
		popBack();
	}
}

void List::display()
{
	std::cout << "Current list (index - value):" << std::endl;

	for(ListElem* temp = head; temp != nullptr; temp = temp -> next)
	{
		std::cout << temp -> position << " - " << temp -> val << std::endl;
	}
	std::cout << "\n\n";
}

bool List::search(int toFind)
{
	ListElem* temp = head;

	for(; temp != nullptr ; temp = temp -> next)
	{
		if(temp -> val == toFind)

			return true;
	}

	return false;
}

void List::pushFront(int value)
{
	ListElem* temp = new ListElem;

	temp -> val = value;
	temp -> prev = nullptr;
	temp -> next = head;
	temp -> position = 0;

	if(head != nullptr)
	{
		temp -> next -> prev = temp;
	}
	else
	{
		tail = temp;
	}

	head = temp;

	while(temp != nullptr)
		{
			temp = temp -> next;
			if(temp == nullptr)
				break;
			temp -> position++;
		}
}

void List::pushBack(int value)
{
	ListElem* temp = new ListElem;

	temp -> val = value;
	temp -> next = nullptr;
	temp -> prev = tail;

	if(tail != nullptr)
	{
		//std::cout << temp -> position << std::endl;
		temp -> position = tail -> position + 1;
		temp -> prev -> next = temp;
	}
	else
	{
		temp -> position = 0;
		head = temp;
	}

	tail = temp;

}

void List::pushInto(int pos, int pushedValue)
{

	if(pos < 0)
	{
		std::cout << "Position cannot be negative" << std::endl;
		return;
	}
	if(pos > tail -> position + 1)
	{
		std::cout << "There are only " << tail -> position << " positions" << std::endl;
		return;
	}

	if(pos == tail -> position + 1)
	{
		pushBack(pushedValue);
		return;
	}
	if(pos == 0 || head == nullptr)
	{
		pushFront(pushedValue);
		return;
	}

	ListElem* temp;

	for(temp = head; temp != nullptr; temp = temp -> next)
	{
		if(temp -> next -> position == pos)
		{
			ListElem* tempPos;
			tempPos = temp -> next;

			while(tempPos != nullptr)
			{
				tempPos -> position++;
				tempPos = tempPos -> next;
			}

			ListElem* newElem = new ListElem;

			newElem -> val = pushedValue;
			newElem -> position = pos;
			newElem -> prev = temp -> next -> prev;
			newElem -> next = temp -> next;

			newElem -> next -> prev = newElem;
			newElem -> prev -> next = newElem;

			return;
		}
	}

}

void List::popFront()
{
	if(head == nullptr)
		return;

	ListElem* temp;
	temp = head;
	head = head -> next;

	delete temp;

	temp = head;

	do
	{
		temp -> position--;
		temp = temp -> next;
	}
	while(temp != nullptr);

	if(head != nullptr)
		head -> prev = nullptr;
}

void List::popBack()
{
	if(head == nullptr)
	{
		return;
	}
	if(tail == nullptr)
		delete head;

	ListElem* temp = tail;

	tail = tail -> prev;

	delete temp;

	if(tail != nullptr)
		tail -> next = nullptr;

}

void List::popBetween(int toDelete)
{
	if(head == nullptr)
	{
		return;
	}

	if(head -> val == toDelete)
	{
		popFront();
	}
	if(tail -> val == toDelete)
	{
		popBack();
	}

	ListElem* temp = head;
	ListElem* tempDelete;

	for(; temp != tail;)
	{
		if(temp -> val == toDelete)
		{
			tempDelete = temp;

			ListElem* tempPos;
			tempPos = temp;

			while(tempPos != nullptr)
			{
				tempPos -> position--;
				tempPos = tempPos -> next;
			}

			temp -> next -> prev = temp -> prev;
			temp -> prev -> next = temp -> next;
			break;
		}

		temp = temp -> next;

		if(temp == tail)
		{
			return;
		}
	}
	delete tempDelete;
}

