#include <iostream>
#include <string>
#include "List.h"
#include "BinaryHeap.h"
#include <cmath>
#include "Array.h"

using namespace std;


string info = R"(
The available options are:
1 - Array

To close the program type '0')";
bool running = true;

int main(int argc, char **argv) {
	cout << "Which type to generate?" <<endl;

BinaryHeap B;

B.add(7);
B.display();
B.add(5);
B.display();
B.add(9);
B.display();
B.add(6);
B.display();
B.add(7);
B.display();
B.add(8);
B.display();
B.add(10);
B.display();
B.add(1);
B.display();
B.add(11);
B.display();

cout << "It's dispose time! \n" << endl;

B.dispose(11);
B.display();
B.dispose(10);
B.display();
B.dispose(7);
B.display();
B.dispose(8);
B.display();
B.dispose(9);
B.display();

/*
	while(running)
	{
		short int choose;
		cin >> choose;

		switch(choose)
		{
		case 1:
			cout << "Array";
			break;
		case 0:
			running = false;
			break;
		default:
			cout << info << endl;
			break;
		}
	}
*/

	return 0;
}
