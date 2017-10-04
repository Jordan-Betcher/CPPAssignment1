/*
 * Person.h
 *
 *  Created on: Oct 2, 2017
 *      Author: Betcher
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <vector>

using namespace std;

class Person
{
		string firstName;
		string lastName;
		string phoneNumber;

	public:
		Person (string);
		Person(string, string, string);
		string getName();
		string getPhoneNumber();
		void print();
		~Person();

};

#endif /* PERSON_H_ */
