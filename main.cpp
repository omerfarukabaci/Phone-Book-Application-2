#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>
#include <string.h>


using namespace std;

Tree t;


void print_menu() {
	cout << endl;
	cout << "Phone list Application" << endl;
	cout << "Choose an operation" << endl;
	cout << "A: Add Record" << endl;
	cout << "U: Update Record" << endl;
	cout << "L: List Records" << endl;
	cout << "E: Exit" << endl;
	cout << endl;
	cout << "Enter a choice {}: ";
}

bool operation(char choice) {
	bool terminate = false;
	int counter = 1;
	usernode toadd;
	switch (choice) {
	case 'A': case 'a':
		cout << "Please enter contact information you want to add" << endl;
		cout << "Name: ";
		cin.ignore(1000, '\n');
		cin.getline(toadd.name, 999);
		cout << "Phone number: ";
		cin >> setw(99) >> toadd.phonenum;
		t.addtreenode(&toadd, t.root, t.levelf(t.root), true);
		cout << "Record added" << endl;
		break;
	case 'S': case 's':
		break;
	case 'U': case 'u':
		cout << "Please enter contact information you want to add" << endl;
		cout << "Name: ";
		cin.ignore(1000, '\n');
		cin.getline(toadd.name, 999);
		cout << "New name: ";
		cin >> setw(99) >> toadd.phonenum;
		if (t.updatenode(t.root, toadd.name, toadd.phonenum))
			cout << "Record updated" << endl;
		else
			cout << "Record is not found" << endl;
		break;

	case 'L': case 'l':
		t.printPreorder(t.root, &counter);
		break;
	case 'E': case 'e':
		terminate = true;
		break;
	default:
		cout << "Error: You have entered an invalid choice" << endl;
		cout << "Please try again {}:";
		cin >> choice;
		terminate = operation(choice);
		break;
	}
	return terminate;
}


int main(){
	bool flag = false;
	char choice;
	while (!flag) {
		print_menu();
		cin >> choice;
		flag = operation(choice);
	}
	t.removeTree(t.root);

	return 0;
}

