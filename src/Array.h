/*
 * Arrays.h
 *
 *  Created on: Mar 16, 2020
 *      Author: Tomasz
 */

#ifndef SRC_ARRAY_H_
#define SRC_ARRAY_H_

class Array {
public:
	int amount;
	int* begin;

	Array(int);
	~Array();
	void display();
	bool search(int);
	void addFront(int);
	void addBack(int);
	void addInto(int, int);
	void deleteBetween(int);
	void deleteFront();
	void deleteBack();

};

#endif /* SRC_ARRAY_H_ */
