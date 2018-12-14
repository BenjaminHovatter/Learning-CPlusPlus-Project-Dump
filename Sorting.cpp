//This program is intened to sort various lists of numbers given by the user, using different sorting methods. The user can choose which sorting method they would like to use,
//Right now, it generates a random array of predetermined size, and sorts it using bubble sorting
#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

void bubbleSort(int list[]);

int sorting() {
	//randomize seed
	srand(time(NULL));

	int placeholder;
	int numbers[10];
	for (int i = 0; i < 10; i++) {
		numbers[i] = rand() % 100;
	}

	//Display array before sorting
	for (int i = 0; i < 10; i++) {
		cout << numbers[i] << ' ';
	}
	bubbleSort(numbers);

	//display array after sorting
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << numbers[i] << ' ';
	}
	
	cin >> placeholder;
	return 0;
}

void bubbleSort(int list[]) {
	bool isSorted = false;

	while(isSorted == false){
		isSorted = true; 
		for (int i = 0; i < 9; i++) {
			if (list[i] > list[i + 1]) {
				isSorted = false; //one set of numbers was out of order. Assume there are others.
				int num1, num2;
				num1 = list[i];
				num2 = list[i + 1];

				list[i] = num2;
				list[i + 1] = num1;
			}
		}

	}
}