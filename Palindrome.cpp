#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int palindrome() {
	while(true!=false){
		string input;
		string afterInput;
		cout << "Type a word." << endl;
		cin >> input;
		for (int i = input.length(); i > 0; i--) {
			afterInput = afterInput + input[i - 1];
		}
		if (input == afterInput) {
			cout << "You typed " + input + ". It's a palindrome!\n\n" << endl;
		}
		else {
			cout << "You typed " + input + ". It is not a palindrome!\n\n" << endl;
		}
	}
	return 0;
}