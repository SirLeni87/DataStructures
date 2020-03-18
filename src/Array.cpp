/*
 * Arrays.cpp
 *
 *  Created on: Mar 16, 2020
 *      Author: Tomasz
 */

#include <iostream>
#include <cstdlib>
#include "Array.h"

Array::Array(int width) {
	amount = width;
	begin = reinterpret_cast<int*>(std::malloc(amount));

	for(int i = 0; i < amount ; i++)
		{
			begin[i] = 0;
		}
}

Array::~Array() {
	free(begin);
}

void Array::display()
{
	for(int i = 0; i < amount ; i++)
	{
		std::cout << i << " - " << begin[i] << std::endl;
	}
	std::cout << std::endl;
}

bool Array::search(int toFind)
{
	for(int i = 0; i < amount; i++)
	{
		if(begin[i] == toFind)
		{
			return true;
		}
	}
	return false;
}

void Array::addFront(int toAdd)
{
	amount++;

	begin = reinterpret_cast<int*>(realloc(begin, amount));

	for(int i = amount - 1; i > 0; i--)
	{
		begin[i] = begin[i - 1];
	}

	begin[0] = toAdd;
}

void Array::addBack(int toAdd)
{
	amount++;

	begin = reinterpret_cast<int*>(realloc(begin, amount));

	begin[amount - 1] = toAdd;
}

void Array::addInto(int toAdd, int index)
{
	if(index < 0)
	{
		std::cout << "Index cannot be negative" << std::endl;
		return;
	}
	if(index > amount)
	{
		std::cout << "There are currently " << amount << " positions! (0 - " << amount - 1 << ")" << std::endl;
		return;
	}

	if(index == amount)
	{
		addBack(toAdd);
		return;
	}
	if(index == 0)
	{
		addFront(toAdd);
		return;
	}

	amount++;

	begin = reinterpret_cast<int*>(realloc(begin, amount));



	for(int i = amount - 1; i > index; i--)
	{
		begin[i] = begin[i - 1];
	}
	begin[index] = toAdd;
}

void Array::deleteFront()
{
	amount--;

	for(int i = 0; i < amount; i++)
	{
		begin[i] = begin[i + 1];
	}

	begin = reinterpret_cast<int*>(realloc(begin, amount));
}

void Array::deleteBack()
{
	amount--;

	begin = reinterpret_cast<int*>(realloc(begin, amount));
}

void Array::deleteBetween(int index)
{
	if(index < 0)
	{
		std::cout << "Index cannot be negative" << std::endl;
		return;
	}
	if(index >= amount)
	{
		std::cout << "There are currently " << amount << " positions! (0 - " << amount - 1 << ")" << std::endl;
		return;
	}

	if(index == amount - 1)
	{
		deleteBack();
		return;
	}
	if(index == 0)
	{
		deleteFront();
		return;
	}

	for(int i = index; i < amount - 1; i++)
	{
		begin[i] = begin[i + 1];
	}

	amount--;

	begin = reinterpret_cast<int*>(realloc(begin, amount));
}

