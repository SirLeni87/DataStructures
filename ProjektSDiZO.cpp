#include <iostream>
#include <string>

using namespace std;

string info = R"(
The available options are:
1 - Array

To close the program type '0')";
bool running = true;

int main(int argc, char **argv) {
	cout << "Which type to generate?" <<endl;

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
//		cout << "lol";
	}


	return 0;
}
