//This program is an introduction to linked lists. I will be adding various functionality based on whatever I feel like practicing/learning.
//Currently, thisn program creates a LinkedList for the user to add data to by appending/insertion. It also allows the user to print and view the linked list.
#include <iostream>
#include <fstream>
#include <string>
#include <ctime> 
#include <cstdlib>

using namespace std;

struct Node {
	int data;
	Node* next = NULL;
};

class LinkedList {

private:
	Node *current = NULL;
	Node *head = NULL;
	Node *temp = NULL;
	Node *newNode = NULL;

public:

	//appent node to end of linked list
	void append(int input) {
		if (head == NULL) {
			head = new Node; // If a head node doesnt exist (no nodes exist), create a new head node
			head->data = input;  //assign the passed input value to the Node's data.
			cout << input << " appended to linked list.\n" << endl;
			return; //
		}
		current = head; //set "reader/tracker" to head node.

			//read through each node until last node is reached (last node has no link, NULL)

		while (current->next != NULL) {

			current = current->next;

		}
		temp = current; //
		current = new Node; //Create node to be appended
		current->data = input;
		current->next = NULL;
		temp->next = current; //Link last node to new node(node to be appended)

		cout << input << " appended to linked list.\n" << endl;
		return;

	}

	//Insert a new node at a given position in the linked list. Positions will be counted where position 1 is the first item.
	void insert(int input, int insertionPosition) {
		if (head == NULL) {
			cout << "Linked list does not have any data, cannot insert.\n" << endl;
			return;
		}
		int position = 1;
		current = head;
		while (position + 1 != insertionPosition) {
			if (current->next == NULL) {
				cout << "Cannot insert at position " << insertionPosition << ", list is " << position - 1 << " nodes long.\n" << endl;
			}
			current = current->next; //advance to next node
			position++;
		}

		temp = current;
		//Determine if a node exists at insertionPosition. If no node exists, simply append a new node.
		if (current->next == NULL) {
			current = new Node; //Create node to be appended
			current->data = input;
			current->next = NULL;
			temp->next = current; //Link last node to new node(node to be appended)
		}
		else {
			current = new Node;
			current->data = input;
			current->next = temp->next;
			temp->next = current;
		}
		cout << input << " inserted at position " << insertionPosition << ".\n" << endl;
		return;
	}

	void printList() {
		//determine if list exists
		if (head != NULL) {
			current = head;
			int position = 1;
			cout << endl;
			while (current->next != NULL) {
				cout << position << ": " << current->data << endl;
				current = current->next;
				position++;
			}
			//list last value
			cout << position << ": " << current->data << endl;
		}
		else {
			cout << "List does not contain any data.\n" << endl;
		}

		return;
	}
};


int linkedList() {
	int placeholder;
	bool done = false;
	LinkedList list;

	cout << "An empty list has been created. ";
	while (done == false) {
		int inputChoice;
		cout << "Choose an option:\n1) Append to list\n2) Insert in list\n3) Print list\n4) Quit" << endl;
		cin >> inputChoice;
		int input;
		int inputLine;

		switch (inputChoice) {
		case 1:
			cout << "Enter an integer :" << endl;
			cin >> input;
			list.append(input);
			cout << endl;
			break;
		case 2:
			int position;
			cout << "Enter an integer or set of integers to be inserted: ";
			cin >> input;
			cout << "\nEnter the position that the integer shoudl be inserted in the list: ";
			cin >> position;
			list.insert(input, position);
			break;
		case 3:
			list.printList();
			break;
		case 4:
			done = true;
			break;
		default:
			cout << inputChoice << " is not a valid option." << endl;
			break;
		}
	}
	return 0;
}

