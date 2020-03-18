/*
 * BinaryHeap.cpp
 *
 *  Created on: Mar 17, 2020
 *      Author: Tomasz
 */

#include "BinaryHeap.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;


BinaryHeap::BinaryHeap() {
	heap = new int[5000];
	counter = 0;
}

BinaryHeap::~BinaryHeap() {
	delete(heap);
}

int BinaryHeap::getParentIndex(int childIndex) const
{
	return ((int)ceil(((float)childIndex)/2) - 1);
}

int BinaryHeap::getBiggerChildIndex(int parentIndex) const
{
	int child1 = 2*parentIndex + 1;
	int child2 = child1 + 1;

	if(heap[child1] > heap[child2])
	{
		return child1;
	}
	else
		return child2;
}

void BinaryHeap::add(int toAdd)
{
	heap[counter] = toAdd;

	int childIndex = counter;
	int parentIndex = getParentIndex(childIndex);

	while(heap[childIndex] > heap[parentIndex])
	{
		swap(heap[childIndex], heap[parentIndex]);

		childIndex = parentIndex;
		parentIndex = getParentIndex(childIndex);
	}

	counter++;
}

void BinaryHeap::dispose(int forDisposal)
{
	for(int i = 0; i < counter; i++)
	{
		if(heap[i] == forDisposal)
		{
			swap(heap[i], heap[counter - 1]);

			heap[counter - 1] = 0;
			counter--;

			int parentIndex = i;
			int childIndex = getBiggerChildIndex(parentIndex);

			while(heap[childIndex] > heap[parentIndex])
			{
				swap(heap[childIndex], heap[parentIndex]);


				parentIndex = childIndex;
				childIndex = getBiggerChildIndex(parentIndex);
			}
			return;
		}
	}
}

void BinaryHeap::display()
{
	int tabLevel = ceil(log2(counter + 1));
	int level = 0;
	int whiteSpace = pow(2, tabLevel) - 1;

	for(int i = 1; i <= counter; i++)
	{
		if(i == pow(2, level))
		{
			cout << endl;
			level++;
			for(int j = (pow(2, tabLevel - level) - 1); j > 0; j--)
			{
				cout << "   " << flush;
			}
		}
		cout << setw(3) << heap[i - 1] << flush;
		for(int j = (pow(2, tabLevel - level + 1) - 1); j > 0; j--)
		{
			cout << "   " << flush;
		}
	}
	cout << endl;
	cout << endl;

	for(int i = 0; i < counter; i++)
	{
		cout << heap[i] << " | " << flush;
	}
	cout << endl;
}



