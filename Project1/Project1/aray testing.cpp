#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	int score;
	string lists[10] = {"Dave", "0","Dan","0", "Abe","0", "Mike","0", "Sam", "0"};
	for (int i = 1; i < 10; i+=2) {
		lists[i] = to_string(rand() % 100);
		cout << lists[i - 1] + " earned " + lists[i] + " points.\n" << endl;
	}
	system("pause");
	return 0;
}