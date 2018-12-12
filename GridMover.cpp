#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;
string grid[9][9] = { { "-","-","-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" },{ "-","-","-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" },{ "-","-","-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" },{ "-","-","-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" },{ "-","-","-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" },{ "-","-","-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" },{ "-","-","-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" },{ "-","-","-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" },{ "-","-","-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" } };
string map = "";
string updateMap() {
	cout << string(60, '\n');
	map = "";
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			map = map + grid[r][c];
		}
		map = map + "\n";
	}
	return map;
}
int gridMover() {
	srand(time(NULL));
	do {
		grid[rand() % 9][rand() % 9] = "X";
		//find starting position
		bool foundSpot = false;
		int row;
		int col;
		while (foundSpot == false) {
			int srow = rand() % 9;
			int scol = rand() % 9;
			if (grid[srow][scol] != "X") {
				grid[srow][scol] = "O";
				cout << srow + " " + scol << endl;
				row = srow;
				col = scol;
				foundSpot = true;
			}
		}
		cout << updateMap() << endl;
		bool end = false;
		do {
			bool correctMove = false;
			int nextMove;
			do {
				int nextMovet;
				cout << " 8 = UP || 4 = LEFT || 6 = RIGHT || 2 = DOWN" << endl;
				cin >> nextMovet;
				if ((nextMovet == 8) || (nextMovet == 4) || (nextMovet == 6) || (nextMovet == 2)) {
					nextMove = nextMovet;
					correctMove = true;
				}
				else {
					cout << "Invalid movement." << endl;
				}
			} while (correctMove == false);
			switch (nextMove) {
				//down
			case 2:
				grid[row][col] = "-";
				if (row + 1 == 9) {
					row = 0;
					if (grid[row][col] == "X") {
						grid[row][col] = "O";
						cout << updateMap() << endl;
						cout << "You found the X!" << endl;
						system("PAUSE");
						grid[row][col] = "-";
						end = true;
					}
					else {
						grid[row][col] = "O";
						cout << updateMap() << endl;
					}
				}
				else {
					row++;
					if (grid[row][col] == "X") {
						grid[row][col] = "O";
						cout << updateMap() << endl;
						cout << "You found the X!" << endl;
						system("PAUSE");
						grid[row][col] = "-";
						end = true;
					}
					else {
						grid[row][col] = "O";
						cout << updateMap() << endl;
					}
				}
				break;
				//left
			case 4:
				grid[row][col] = "-";
				if (col - 1 == -1) {
					col = 8;
					if (grid[row][col] == "X") {
						grid[row][col] = "O";
						cout << updateMap() << endl;
						cout << "You found the X!" << endl;
						system("PAUSE");
						grid[row][col] = "-";
						end = true;
					}
					else {
						grid[row][col] = "O";
						cout << updateMap() << endl;
					}
				}
				else {
					col--;
					if (grid[row][col] == "X") {
						grid[row][col] = "O";
						cout << updateMap() << endl;
						cout << "You found the X!" << endl;
						system("PAUSE");
						grid[row][col] = "-";
						end = true;
					}
					else {
						grid[row][col] = "O";
						cout << updateMap() << endl;
					}
				}
				break;
				//right
			case 6:
				grid[row][col] = "-";
				if (col + 1 == 9) {
					col = 0;
					if (grid[row][col] == "X") {
						grid[row][col] = "O";
						cout << updateMap() << endl;
						cout << "You found the X!" << endl;
						system("PAUSE");
						grid[row][col] = "-";
						end = true;
					}
					else {
						grid[row][col] = "O";
						cout << updateMap() << endl;
					}
				}
				else {
					col++;
					if (grid[row][col] == "X") {
						grid[row][col] = "O";
						cout << updateMap() << endl;
						cout << "You found the X!" << endl;
						system("PAUSE");
						grid[row][col] = "-";
						end = true;
					}
					else {
						grid[row][col] = "O";
						cout << updateMap() << endl;
					}
				}
				break;
				//up
			case 8:
				grid[row][col] = "-";
				if (row - 1 == -1) {
					row = 8;
					if (grid[row][col] == "X") {
						grid[row][col] = "O";
						cout << updateMap() << endl;
						cout << "You found the X!" << endl;
						system("PAUSE");
						grid[row][col] = "-";
						end = true;
					}
					else {
						grid[row][col] = "O";
						cout << updateMap() << endl;
					}
				}
				else {
					row--;
					if (grid[row][col] == "X") {
						grid[row][col] = "O";
						cout << updateMap() << endl;
						cout << "You found the X!" << endl;
						system("PAUSE");
						grid[row][col] = "-";
						end = true;
					}
					else {
						grid[row][col] = "O";
						cout << updateMap() << endl;
					}
				}
				break;
			default:
				break;
			}
		} while (end == false);
	}while (true != false);
	return 0;
}