/*
 * Person.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Betcher
 */
#include <sstream>
#include <string>
#include "Person.h"
#include <vector>
#include <iostream>
using namespace std;

Person::Person(std::string line)
{
	std::istringstream lineStream(line);
	getline(lineStream, firstName, ' ');
	getline(lineStream, lastName, ' ');
	getline(lineStream, phoneNumber, ' ');
}

Person::Person(string _firstName, string _lastName, string _phoneNumber)
{
	firstName = _firstName;
	lastName = _lastName;
	phoneNumber = _phoneNumber;
}

string Person::getName()
{
	string name;
	name = firstName + " " + lastName;
	return name;
}

string Person::getPhoneNumber()
{
	return phoneNumber;
}


void Person::print()
{
	cout << firstName << " " << lastName << " " << phoneNumber;
}

Person::~Person()
{
	// TODO Auto-generated destructor stub
}

