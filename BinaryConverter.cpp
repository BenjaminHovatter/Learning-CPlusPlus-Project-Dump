#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>

using namespace std;

// 25/16 = 1    
// r 9
// 9/8 = 1
// r 1
// 1/4 = 0
// r 1
// 1/2 = 0
// r 1
// 1/1 = 1
// r = 0

//floor(9/16)
//

int binaryConverter() {
	while (true != false) {
		float input;
		int next;
		string binary = "";
		bool checked = false;
		cout << "Enter a positive number to convert to binary." << endl;
		cin >> input;
		for (float i = 40; i > -1; i--) {
			if ((input > pow(2, i)) && checked != true) {
				binary += to_string(int(floor(input / pow(2, i))));
				next = int(fmod(input, pow(2, i)));
				checked = true;
			}
			else if (checked == true) {
				binary += to_string(int(floor(next / pow(2, i))));
				next = int(fmod(float(next), pow(2, i)));
			}
		}
		if (int(input) == 0) {
			cout << "0 is 0 in binary!\n" << endl;
		}
		else if (int(input) == 1) {
			cout << "1 is 1 in binary!\n" << endl;
		}
		else if (int(input) == 2) {
			cout << "2 is 10 in binary!\n" << endl;
		}
		else if (int(input) == 3) {
			cout << "3 is 11 in binary!\n" << endl;
		}
		else if (int(input) == 4) {
			cout << "4 is 100 in binary!\n" << endl;
		}
		else if (binary != "") {
			cout << to_string(int(input)) + " is " + binary + " in binary!\n" << endl;
		}
		else {
			cout << to_string(int(input)) + " is not a positive number.\n" << endl;
		}
	}
}