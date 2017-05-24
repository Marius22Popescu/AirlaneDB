//Declaring variable
#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//Passanger Class Prototype
class Passanger
{
private:

	string FirstName;
	string LastName;
	string Address;
	string Phone;

public:

	Passanger();
	
	void setFirstName(string n);
	string getFirstName();
	void setLastName(string n);
	string getLastName();
	void setAddress(string n);
	string getAddress();
	void setPhone(string n);
	string getPhone();
	virtual ~Passanger();
	bool operator== (Passanger & other);
	bool operator!= (Passanger & other);
	bool operator< (Passanger & other);
	friend ostream& operator<< (ostream & os, Passanger & other);
};

//initializing the object: Passanger
Passanger::Passanger()
{
	FirstName = " ";
	LastName = " ";
	Address = " ";
	Phone = " ";
	
}

Passanger::~Passanger()
{

}

//getters and setters
void Passanger::setFirstName(string n)
{
	FirstName = n;
}

string Passanger::getFirstName()
{
	return FirstName;
}

void Passanger::setLastName(string n)
{
	LastName = n;
}

string Passanger::getLastName()
{
	return LastName;
}

void Passanger::setAddress(string n)
{
	Address = n;
}

string Passanger::getAddress()
{
	return Address;
}

void Passanger::setPhone(string n)
{
	Phone = n;
}

string Passanger::getPhone()
{
	return Phone;
}

// Overloding the "==" operator
bool Passanger::operator== (Passanger & other)
{
	if (getFirstName() == other.getFirstName() && getLastName() == other.getLastName())
		return true;
	return false;
}

// Overloding the " != " operator
bool Passanger::operator!= (Passanger & other)
{
	if (getFirstName() != other.getFirstName() && getLastName() != other.getLastName())
		return true;
	return false;
}

// Overloding the "<<" operator
ostream& operator<<(ostream & os, Passanger & other){
		os << " " << other.getFirstName() << " " << other.getLastName() << " [" << other.getAddress() << "] [" << other.getPhone() << "]\n";
	
	return os;
}

//Overloading the "<" operator
bool Passanger::operator< (Passanger & other)
{
	if (getLastName() <= other.getLastName())
		return true;
	return false;
}
