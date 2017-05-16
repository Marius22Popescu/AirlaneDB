// arlineDB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "Passenger.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//template <class T>
	OrderedLinkedList<Passanger> mylist;
	char menuSelection;
	string lastName, firstName, address, phone;
	// Ask the user which action want to do and perform the task
	do {
		cout << "(A)dd | (S)earch | (D)elete | (L)ist | (Q)uit: ";
		cin >> menuSelection;

		// Prompt user for new name and phone number to add to database
		if (menuSelection == 'A' || menuSelection == 'a')
		{
			cout << "Enter first name: \n";
			cin.ignore();
			getline(cin, firstName);
			cout << "Enter last name: \n";

			getline(cin, lastName);
			cout << "Enter address: \n";
			getline(cin, address);
			cout << "Enter phone: \n";
			cin >> phone;

		Passanger p;
		p.setFirstName(firstName);
		p.setLastName(lastName);
		p.setAddress(address);
		p.setPhone(phone);
		mylist.insert_last(p);

		}
		else if (menuSelection == 'L' || menuSelection == 'l')
		{
			cout << mylist << endl;
		}
		// Prompt user for name to search 
		if (menuSelection == 'S' || menuSelection == 's')
		{ 
			cout << "Enter the last name: ";
			cin.ignore();
			getline(cin, lastName);
			cout << "Enter the first name: ";
			cin.ignore();
			getline(cin, firstName);
		//	Passanger temp;                //here is the problem !!!!
		//	temp.setFirstName(firstName); //
		//	temp.setLastName(lastName);
		//	mylist.search(temp);
		}
		// Prompt user for name to delete 
		if (menuSelection == 'D' || menuSelection == 'd')
		{
			cout << "Enter the last name: ";
			cin.ignore();
			getline(cin, lastName);
			cout << "Enter the first name: ";
			cin.ignore();
			getline(cin, firstName);
		//	mylist.delete_node(z);
			cout << "The passenger was deleted.\n";
		}
	} while (menuSelection != 'Q' && menuSelection != 'q');

	//cout << mylist << endl;
	cout << "size:" << mylist.length() << endl;

	cout << "Enter a number to serch\n";
	int y;
	cin >> y;
	//cout << "this is your item " << mylist.search(y) << endl;

	cout << "Enter a number to delete\n";
	int z;
	cin >> z;
	cout << "the number was deleted\n";
	//mylist.delete_node(z);
	cout << mylist << endl;

	mylist.destroy_list();
	cout << mylist;
	cout << "size:" << mylist.length() << endl;

	system("pause");
	return 0;
}

