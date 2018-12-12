#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;

string board;
string choices[3][3] = { { " ", " ", " " },{ " ", " ", " " },{ " ", " ", " " } };
string updateBoard() {
	board = { choices[0][0] + " | " + choices[0][1] + " | " + choices[0][2] + "\n" + "----------\n" +
			  choices[1][0] + " | " + choices[1][1] + " | " + choices[1][2] + "\n" + "----------\n" +
			  choices[2][0] + " | " + choices[2][1] + " | " + choices[2][2] + "\n" };
	return board;
}

void clearChoices() {
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			choices[r][c] = " ";
		}
	}
}

int winCheck() {
	// Check X win

	if (((choices[0][0] == "X") && (choices[0][1] == "X") && (choices[0][2] == "X")) || ((choices[1][0] == "X") && (choices[1][1] == "X") && (choices[1][2] == "X")) || ((choices[2][0] == "X") && (choices[2][1] == "X") && (choices[2][2] == "X")) || ((choices[0][0] == "X") && (choices[1][1] == "X") && (choices[2][2] == "X")) || ((choices[0][2] == "X") && (choices[1][1] == "X") && (choices[2][0] == "X")) || ((choices[0][0] == "X") && (choices[1][0] == "X") && (choices[2][0] == "X")) || ((choices[0][1] == "X") && (choices[1][1] == "X") && (choices[2][1] == "X")) || ((choices[0][2] == "X") && (choices[1][2] == "X") && (choices[2][2] == "X"))) {
		int userInput;
		cout << "You win! Would you like to play again?\nYes = 1 || No = 2\n" << endl;
		bool correctInput = false;
		do {
			cin >> userInput;
			if (userInput == 1) {
				system("CLS");
				correctInput = true;
				return userInput;
			}
			else if (userInput == 2) {
				correctInput = true;
				return userInput;
			}
			else {
				cout << "Invalid answer." << endl;
			}
		} while (correctInput == false);

	}//Check O win
	else if (((choices[0][0] == "O") && (choices[0][1] == "O") && (choices[0][2] == "O")) || ((choices[1][0] == "O") && (choices[1][1] == "O") && (choices[1][2] == "O")) || ((choices[2][0] == "O") && (choices[2][1] == "O") && (choices[2][2] == "O")) || ((choices[0][0] == "O") && (choices[1][1] == "O") && (choices[2][2] == "O")) || ((choices[0][2] == "O") && (choices[1][1] == "O") && (choices[2][0] == "O")) || ((choices[0][0] == "O") && (choices[1][0] == "O") && (choices[2][0] == "O")) || ((choices[0][1] == "O") && (choices[1][1] == "O") && (choices[2][1] == "O")) || ((choices[0][2] == "O") && (choices[1][2] == "O") && (choices[2][2] == "O"))) {
		int userInput;
		cout << "You lost! Would you like to play again?\nYes = 1 || No = 2\n" << endl;
		bool correctInput = false;
		do {
			cin >> userInput;
			if (userInput == 1) {
				system("CLS");
				correctInput = true;
				return userInput;
			}
			else if (userInput == 2) {
				correctInput = true;
				return userInput;
			}
			else {
				cout << "Invalid answer." << endl;
			}
		} while (correctInput == false);

	}
	bool freeSpace = false;
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (choices[r][c] == " ") {
				freeSpace = true;
			}
		}
	}
	if (freeSpace == false) {
		int userInput;
		cout << "It's a tie! Would you like to play again?\nYes = 1 || No = 2\n" << endl;
		bool correctInput = false;
		do {
			cin >> userInput;
			if (userInput == 1) {
				system("CLS");
				correctInput = true;
				return userInput;
			}
			else if (userInput == 2) {
				correctInput = true;
				return userInput;
			}
			else {
				cout << "Invalid answer." << endl;
			}
		} while (correctInput == false);
	}
	return 0;

}
void randomPlacer() {
	int rowi;
	int coli;
	bool found = false;
	do {
		rowi = rand() % 3;
		coli = rand() % 3;
		if ((choices[rowi][coli] != "X") && (choices[rowi][coli] != "O")) {
			choices[rowi][coli] = "O";
			found = true;
		}
	} while (found == false);
	system("CLS");
	//return updateBoard();
}
int ticTacToe() {
	srand(time(NULL));
	//string x, o;
	bool end = false;
	string board;
	//Begin Game
	do {
		string row;
		string col;


		bool userChoice = false;
		do {
			system("CLS");
			cout << updateBoard() << endl;
			cout << "What row will you place your X?" << endl;
			cin >> row;
			cout << "What column will you place your X?" << endl;
			cin >> col;
			int rowi = stoi(row);
			int coli = stoi(col);

			if ((0 < rowi < 4) && (0 < coli < 4)) {
				if ((choices[rowi - 1 ][coli - 1] != "X") && (choices[rowi -1][coli-1] != "O")) {
					choices[rowi - 1][coli - 1] = "X";
					userChoice = true;
					//system("CLS");
					cout << updateBoard() << endl;
				}
				else {
					cout << "That spot has been taken!" << endl;
				}
			}else {
				cout << "You entered an invalid row or column!" << endl;
			};
		} while (userChoice == false);

			/* 0 = not done
			   1 = end of game, play again
			   2 = end of game, stop playing */
		
		//Check for win
		switch (winCheck()) {
		case 1:
			clearChoices();
			break;
		case 2:
			end = true;
			exit(0);
			break;
		default:
			cout << "" << endl;
			break;
		}
		
		randomPlacer();
		//cout << randomPlacer() << endl;
		//Check for win again
		switch (winCheck()) {
		case 1:
			clearChoices();
			break;
		case 2:
			end = true;
			break;
		default:
			cout << "" << endl;
			break;
		}

	} while (end == false);
	return 0;
}
