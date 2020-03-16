/*
 * List.h
 *
 *  Created on: Mar 14, 2020
 *      Author: Tomasz
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>

struct ListElem {
	int val;
	int position;
	ListElem* next;
	ListElem* prev;
};

class List
{

public:
	ListElem* head;
	ListElem* tail;

	List();
	~List();
	void display();
	bool search(int toFind);
	void pushFront(int value);
	void pushBack(int value);
	void pushInto(int position, int pushedValue);
	void popBetween(int toDelete);
	void popFront();
	void popBack();
};


#endif /* LIST_H_ */
