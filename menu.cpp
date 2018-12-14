#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int ticTacToe();
int palindrome();
int binaryConverter();
int gridMover();
int fileReader();
int linkedList();
int sorting();

int main() {
	int choice;
	cout << "Welcome to the Project1 menu. Choose a program to run:\nPalindrome: 1 || Grid Mover: 2 || Tic Tac Toe: 3 || Binary Converter: 4 || File Reader: 5 || Linked List Maker: 6\nSorting: 7" << endl;
	bool chosen = false;
	do {
		cin >> choice;
		switch (choice) {
		case 1:
			string(60, '\n');
			palindrome();
			chosen = true;
			break;
		case 2:
			string(60, '\n');
			gridMover();
			chosen = true;
			break;
		case 3:
			string(60, '\n');
			ticTacToe();
			chosen = true;
			break;
		case 4:
			string(60, '\n');
			binaryConverter();
			chosen = true;
			break;
		case 5:
			string(60, '\n');
			fileReader();
			chosen = true;
			break;
		case 6:
			string(60, '\n');
			linkedList();
			chosen = true;
			break;
		case 7:
			string(60, '\n');
			sorting();
			chosen = true;
			break;
		default:
			cout << "'" << choice << "' is not an option. Please choose again.\n" << endl;
			break;
		}
	} while (chosen == false);
	return 0;
}
