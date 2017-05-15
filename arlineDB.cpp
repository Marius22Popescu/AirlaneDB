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
	cout << "Enter a number:";
	int x;
	cin >> x;
	while (x != -99){
		Passanger p;
		p.setFirstName("Marius");
		p.setLastName("Popescu");
		p.setAddress("10407 Rosewood");
		p.setPhone("4253435022");
		mylist.insert_last(p);
		cout << "Enter a number:";
		cin >> x;
	}
	cout << mylist << endl;
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

