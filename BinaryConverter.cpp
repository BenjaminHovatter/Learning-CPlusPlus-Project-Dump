#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <math.h>

using namespace std;

void decimalToBinary();
void binaryToDecimal();

int binaryConverter() {

	while (true != false) {
		double input; // int values for the number without the decimal, and an int value for strictly the decimal.
		cout << "Convert 1) Binary to Decimal, or  2) Decimal to Binary?" << endl;
		cin >> input;
		switch (static_cast<int>(input)) {
		case 1:
			binaryToDecimal();
			break;
		case 2:
			decimalToBinary();
			break;
		default:
			cout << input << " is not a valid option." << endl;
			break;
		}
	}

	return 0;
}


void decimalToBinary() {
	double input, integer, frac;
	int wholeLog2, fracLog2;
	string binary, fracBinary;
	cout << "Enter a positive number to convert to binary. Currently only whole numbers are supported." << endl;
	cin >> input;
	input = static_cast<int>(fabs(input));
	//determine if user input is a while number or not. if it is, seperate integer from decimal/fraction
/*	if (floor(input) != input) {
		frac = modf(fabs(input), &integer);
		wholeLog2 = log2(integer);
		fracLog2 = log2(frac);

		//do binary calculations for fraction portion
		int arg, binaryDigit;
		arg = fracLog2;
		fracBinary = ".";

		for (int i = floor(fracLog2); i > 0; --i) {
			if (pow(2, -i) <= arg) {
				binaryDigit = arg / pow(2, -i);
				fracBinary += to_string(binaryDigit);
				arg = arg % static_cast<int>(pow(2, -i));
			}
		}

	}
	else {
		fracBinary = "";
		wholeLog2 = log2(input);
	}*/
	fracBinary = "";
	wholeLog2 = log2(input);

	int arg, binaryDigit;
	arg = input;

	for (int i = floor(wholeLog2); i > -1; --i) {
		//determine if 2^i is less than or equal whatever our log2() or remainder number. 
		if (pow(2, i) <= arg) {
			//make the binary digit equal to the leading integer value of the previous (remainder/2^i)
			binaryDigit = arg / pow(2, i);
			binary += to_string(binaryDigit);
			//find remainder of (current remainder/2^i)
			arg = arg % static_cast<int>(pow(2, i));
		}
		else {
			binary += "0";
		}
	}

	while (binary.length() % 4 != 0) {
		binary.insert(0, "0");
	}
	cout << input << " is " << binary << fracBinary << " in binary." << endl;
	return;
}


//todo: handle decimals.
void binaryToDecimal() {
	string input, wholeBinary, fracBinary;
	double decimal = 0;
	bool validInput = false;
	while (validInput == false) {
		cout << "Enter a binary number to convert to a decimal. Currently, only nonl-fractional binary numbers are supported." << endl;
		cin >> input;
		
		/*iterate through each number in the given binary value. Validate that the number is a one or a zero, and compute each. If a value is not a 1 or a 0, stop calculation,
		output an error statement, and*/
		for (int i = 0; i < input.length(); ++i) {
			if (input.substr(i, 1) == "0" || input.substr(i, 1) == "1") {
				decimal += (stod(input.substr(i, 1))*pow(2, input.length() - 1 - i));
			}
			else {
				cout << input + " is not a binary number." << endl;
				continue;
			}
		}
		validInput = true;
	}

	cout << input << " is " << decimal << " in decimal form." << endl;
	return;
}
