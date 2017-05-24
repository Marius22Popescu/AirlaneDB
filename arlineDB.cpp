//arlineDB.cpp : Defines the entry point for the console application.
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


int main()
{
	OrderedLinkedList<Passanger> mylist100;
	OrderedLinkedList<Passanger> mylist200;
	OrderedLinkedList<Passanger> mylist300;
	OrderedLinkedList<Passanger> mylist400;
	string flight;
	char menuSelection;
	string lastName, firstName, address, phone;
	// Ask the user which action want to do and perform the task
	do {
		cout << "(A)dd | (S)earch | (D)elete | (L)ist | (Q)uit: ";
		cin >> menuSelection;

		// Prompt user for name, phone number and addres to add to database
		if (menuSelection == 'A' || menuSelection == 'a')
		{
			cout << "Enter the flight number: \n";
			cin >> flight;
			cout << "Enter first name: \n";
			cin.ignore();
			getline(cin, firstName);
			cout << "Enter last name: \n";
			cin >> lastName;
			cout << "Enter address: \n";
			cin.ignore();
			getline(cin, address);
			cout << "Enter phone: \n";
			getline(cin, phone);

			//instantiate passanger p and insert the data
		Passanger p;
		p.setFirstName(firstName);
		p.setLastName(lastName);
		p.setAddress(address);
		p.setPhone(phone);

			//input the object in the right linked list 
		if (flight == "100")
			mylist100.insert(p);
		else if (flight == "200")
			mylist200.insert(p);
		else if (flight == "300")
			mylist300.insert(p);
		else if (flight == "400")
			mylist400.insert(p);
		else
			cout << "WRONG FLIGHT NUMBER PLEASE ADD AGAIN!!!\n";

		}
			//user option to list all pasangers from one flight
		else if (menuSelection == 'L' || menuSelection == 'l')
		{
			cout << "Enter the flight number:\n";
			cin >> flight;
			if (flight == "100")
				cout << mylist100 << endl;
			else if (flight == "200")
				cout << mylist200 << endl;
			else if (flight == "300")
				cout << mylist300 << endl;
			else if (flight == "400")
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
			Passanger temp;             //create a temporar pasanger to pass it like parameter for search function
			Passanger *result;			//create a temporar pasanger to return the inhormation  for search function
			temp.setFirstName(firstName);
			temp.setLastName(lastName);
			
				result = mylist100.search(temp);
				if (result != NULL){
					cout << "Flight Number: 100\n";
					cout << *result << endl;
				}
				else{
					result = mylist200.search(temp);
					if (result != NULL){
						cout << "Flight Number: 200\n";
						cout << *result << endl;
					}
					else{
						result = mylist300.search(temp);
						if (result != NULL){
							cout << "Flight Number: 300\n";
							cout << *result << endl;
						}
						else{
							result = mylist400.search(temp);
							if (result != NULL){
								cout << "Flight Number: 400\n";
								cout << *result << endl;
							}
							else
								cout << "not found" << endl;
						}
					}
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

			if (flight == "100"){
				mylist100.delete_node(temp1);
				cout << "The passenger was deleted!\n";
			}
			else if (flight == "200"){
				mylist200.delete_node(temp1);
				cout << "The passenger was deleted!\n";
			}
			else if (flight == "300"){
				mylist300.delete_node(temp1);
				cout << "The passenger was deleted!\n";
			}
			else if (flight == "400"){
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

	return 0;
}

/*******************************************************END OF PROGRAM*************************************************************/