#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;
int fileReader() {
	bool quit = false;
	do{
		string line;
		string fileName = "";
		while (fileName == "") {
			cout << "Enter the name of the file you want to read." << endl;
			cin >> fileName;
		}
		ifstream data(fileName+".txt");
		data.open();
		if (data.is_open()) {
			while (getline(data, line)) {
				cout << line + '\n' << endl;
			}
		}
		else {
			bool valid = false;
			while (valid == false) {
				string qInput;
				cout << "Unable to open " + fileName + ". \nQuit?  Y/N" << endl;
				cin >> qInput;
				if (tolower(stoi(qInput)) == stoi("y")) {
					valid = true;
					quit = true;
				}
				else if (tolower(stoi(qInput)) != stoi("n")) {
					cout << "Sorry, that answer was not recognised." << endl;
				}
				else {
					valid = true;
				}
			}
		}
	} while(quit == false);
	return 0;
}