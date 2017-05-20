// arlineDB.cpp : Defines the entry point for the console application.
//Marius Popescu
//CS300
//Assignment 2
//05/2017

//This is a data base for airline company that has 4 flight each day. For each flight it is possible to keep a list of passengers 
//this database keeps thepassangers sorted by their last names in ascending order

//Include directive:
#include "stdafx.h"
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "Passenger.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//template <class T>
	OrderedLinkedList<Passanger> mylist100;
	OrderedLinkedList<Passanger> mylist200;
	OrderedLinkedList<Passanger> mylist300;
	OrderedLinkedList<Passanger> mylist400;

	int flight;
	char menuSelection;
	string lastName, firstName, address, phone;
	// Ask the user which action want to do and perform the task
	do {
		cout << "(A)dd | (S)earch | (D)elete | (L)ist | (Q)uit: ";
		cin >> menuSelection;

		// Prompt user for new name and phone number to add to database
		if (menuSelection == 'A' || menuSelection == 'a')
		{
			cout << "Enter the flight number: \n";
			cin >> flight;
			cout << "Enter first name: \n";
			cin >> firstName;
			cout << "Enter last name: \n";
			cin >> lastName;
			cout << "Enter address: \n";
			cin.ignore();
			getline(cin, address);
			cout << "Enter phone: \n";
			cin >> phone;

			//instantiate passanger p and insert the data
		Passanger p;
		p.setFirstName(firstName);
		p.setLastName(lastName);
		p.setAddress(address);
		p.setPhone(phone);

		if (flight == 100)
			mylist100.insert(p);
		else if (flight == 200)
			mylist200.insert(p);
		else if (flight == 300)
			mylist300.insert(p);
		else if (flight == 400)
			mylist400.insert(p);
		else
			cout << "WRONG FLIGHT NUMBER PLEASE ADD AGAIN!!!\n";

		}
		else if (menuSelection == 'L' || menuSelection == 'l')
		{
			cout << "Enter the flight number:\n";
			cin >> flight;
			if (flight == 100)
				cout << mylist100 << endl;
			else if (flight == 200)
				cout << mylist200 << endl;
			else if (flight == 300)
				cout << mylist300 << endl;
			else if (flight == 400)
				cout << mylist400 << endl;
			else
				cout << "WRONG FLIGHT NUMBER PLEASE TRY AGAIN!!!\n";
		}

		// Prompt user for name to search and do the search 
		if (menuSelection == 'S' || menuSelection == 's')
		{ 
			cout << "Enter the last name: ";
			cin >> lastName;
			cout << "Enter the first name: ";
			cin >> firstName;
			Passanger temp;                
			temp.setFirstName(firstName);
			temp.setLastName(lastName);
			cout << "Enter the flight number:";  // here is a problem, if I search in a wrong list the program, the program will crash because
			cin >> flight;                       // because the search function needs to return a object not 0
			if (flight == 100){
				temp = mylist100.search(temp);
				cout << temp << endl;
			}
			else if (flight == 200){
				temp = mylist200.search(temp);
				cout << temp << endl;
			}
			else if (flight == 300){
				temp = mylist300.search(temp);
				cout << temp << endl;
			}
			else if (flight == 400){
				temp = mylist400.search(temp);
				cout << temp << endl;
			}
		}
		// Prompt user for name to delete 
		if (menuSelection == 'D' || menuSelection == 'd')
		{
			cout << "Enter the flight number:";
			cin >> flight;
			cout << "Enter the last name: ";
			cin >> lastName;
			cout << "Enter the first name: ";
			cin >> firstName;
			Passanger temp1;
			temp1.setFirstName(firstName);
			temp1.setLastName(lastName);

			if (flight == 100){
				mylist100.delete_node(temp1);
				cout << "The passenger was deleted!\n";
			}
			else if (flight == 200){
				mylist200.delete_node(temp1);
				cout << "The passenger was deleted!\n";
			}
			else if (flight == 300){
				mylist300.delete_node(temp1);
				cout << "The passenger was deleted!\n";
			}
			else if (flight == 400){
				mylist400.delete_node(temp1);
				cout << "The passenger was deleted!\n";
			}
			else
				cout << "WRONG FLIGHT NUMBER PLEASE DELETE AGAIN!!!\n";


			
		}
	} while (menuSelection != 'Q' && menuSelection != 'q');

	//destroing the list 
	mylist100.destroy_list();
	mylist200.destroy_list();
	mylist300.destroy_list();
	mylist400.destroy_list();

	system("pause");
	return 0;
}

/*******************************************************END OF PROGRAM***************************************************************/