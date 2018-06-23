#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
int ticTacToe();
int palindrome();
int binaryConverter();
int gridMover();
int fileReader();

int main() {
	int choice;
	cout << "Welcome to the Project1 menu. Choose a program to run:\nPalindrome: 1 || Grid Mover: 2 || Tic Tac Toe: 3 || Binary Converter: 4 || FIle Reader: 5\n" << endl;
	bool chosen = false;
	do {
		cin >> choice;
		if ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5)) {
			cout << "'" + to_string(choice) + "' is not an option. Please choose again.\n" << endl;
		}
		else {
			if (choice == 1) {
				string(60, '\n');
				palindrome();
				chosen = true;
			}
			else if (choice == 2) {
				string(60, '\n');
				gridMover();
				chosen = true;
			}
			else if (choice == 3) {
				string(60, '\n');
				ticTacToe();
				chosen = true;
			}
			else if (choice == 4) {
				string(60, '\n');
				binaryConverter();
				chosen = true;
			}
			else {
				string(60, '\n');
				fileReader();
				chosen = true;
			}
		}
	} while (chosen == false);
	return 0;
}
