/*
 * Person.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Betcher
 */
#include "Contact.h"

#include <sstream>
#include <string>
#include <vector>
#include <iostream>

Contact::Contact()
{
}

Contact::Contact(std::string line)
{
	std::istringstream lineStream(line);
	getline(lineStream, firstName, ' ');
	getline(lineStream, lastName, ' ');
	getline(lineStream, phoneNumber, ' ');
}

Contact::Contact(std::string name, std::string _phoneNumber)
{
	std::istringstream lineStream(name);
	getline(lineStream, firstName, ' ');
	getline(lineStream, lastName, ' ');
	phoneNumber = _phoneNumber;
}

Contact::Contact(std::string _firstName, std::string _lastName, std::string _phoneNumber)
{

	firstName = _firstName;
	lastName = _lastName;
	phoneNumber = _phoneNumber;
}

std::string Contact::getName()
{
	std::string name;
	name = firstName + " " + lastName;
	return name;
}

std::string Contact::getPhoneNumber()
{
	return phoneNumber;
}

bool operator ==(const Contact &contact1, const Contact &contact2)
{
	return contact1.firstName + " " + contact1.lastName == contact2.firstName + " " + contact2.lastName;
}

void Contact::print()
{
	std::cout << firstName << " " << lastName << " " << phoneNumber << std::endl;
}

Contact::~Contact()
{
	// TODO Auto-generated destructor stub
}

