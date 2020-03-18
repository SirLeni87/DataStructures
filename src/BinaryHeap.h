/*
 * BinaryHeap.h
 *
 *  Created on: Mar 17, 2020
 *      Author: Tomasz
 */

#ifndef SRC_BINARYHEAP_H_
#define SRC_BINARYHEAP_H_

class BinaryHeap {
public:
	int* heap;
	int counter;

	BinaryHeap();
	~BinaryHeap();
	void display();
	bool search(int);
	void sort();
	void add(int);
	void dispose(int);

protected:
	int getParentIndex(int childIndex) const;
	int getBiggerChildIndex(int parentIndex) const;
};

#endif /* SRC_BINARYHEAP_H_ */
