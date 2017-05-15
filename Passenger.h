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

