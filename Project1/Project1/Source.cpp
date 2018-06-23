#include <iostream>
#include <fstream>

using namespace std;
int main() {
	int grade;
	string userGrade;
	bool quit = false;
	int userQuit;
	do {
		cout << "Enter your grade:" << endl;
		cin >> grade;
		if (grade > 89) {
			cout << "You earned an A!" << endl;
		}
		else if (grade > 79) {
			cout << "You earned a B!" << endl;
		}
		else if (grade > 69) {
			cout << "You earned a C!" << endl;
		}
		else if (grade > 59) {
			cout << "You earned a D! :(" << endl;
		}
		else if (grade < 50 ) {
			cout << "You earned an F! Sorry, you failed." << endl;
		}
		cout << "Quit? \n0 = Yes || 1= No\n" << endl;
		cin >> userQuit;
		if (userQuit == 0) {
			quit = true;
		}
		
	} while (quit != true);
	return 0;
}
