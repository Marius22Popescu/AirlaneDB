#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


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
	
	friend ostream& operator<< (ostream & os, Passanger & other);
};


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

bool Passanger::operator== (Passanger & other)
{
	if (getFirstName() == other.getFirstName() && getLastName() == other.getLastName())
		return true;
	return false;
}

bool Passanger::operator!= (Passanger & other)
{
	if (getFirstName() != other.getFirstName() && getLastName() != other.getLastName())
		return false;
	return true;
}


ostream& operator<<(ostream & os, Passanger & other){
		os << " " << other.getFirstName() << " " << other.getLastName() << " [" << other.getAddress() << "] [" << other.getPhone() << "]\n";
	
	return os;
}