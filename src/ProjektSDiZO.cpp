#include <iostream>
#include <string>
#include "List.h"

using namespace std;


string info = R"(
The available options are:
1 - Array

To close the program type '0')";
bool running = true;

int main(int argc, char **argv) {
	cout << "Which type to generate?" <<endl;

	List L;

	L.display();
	for(int i = 5; i < 100; i += 5)
	{
		L.pushFront(i);
	}

	for(int i = 1000; i < 2000; i += 100)
		{
			L.pushBack(i);
		}

	L.display();
	if(L.search(5))
		cout << "It's there" << endl;
	else
			cout << "It's not there" << endl;

	if(L.search(450))
	{
		cout << "It's there" << endl;
	}
	else
		cout << "It's not there" << endl;

	List L2;

	for(int i = 1000; i < 2000; i += 100)
			{
				L2.pushBack(i);
			}
	L2.display();

	L2.popFront();
	L2.popFront();

	L2.display();

	cout <<"Now it's popBetween time \n" << endl;

	L.popBetween(30);
	L.popBetween(9435430);
	L.popBetween(1000);
	L.popBetween(1500);
	L.popBetween(95);
	L.popBetween(1900);
	L.display();

	cout <<"Now it's pushInto time \n" << endl;

	L2.pushInto(-5, 500);
	L2.pushInto(700, 500);
	L2.pushInto(0, 999);
	L2.pushInto(8, 999);
	L2.pushInto(10, 999);
	L2.pushInto(5, 999);
	L2.pushInto(5, 999);
	L2.pushInto(5, 999);

	L2.display();

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
