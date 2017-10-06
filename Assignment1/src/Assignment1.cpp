//============================================================================
// Name        : Assignment1.cpp
// Author      : Jordan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>

#include "Contact.h"

using namespace std;

vector<string> getLinesFromFile(string location);
vector<Contact> getContactsFromLines(vector<string> lines);
void getContactsFromVector(vector<Contact> lines);
void deleteNewLine(string &line);
//test
string textFileName = "phonebook.txt";
Contact arrayContacts[151424*2];
int contactsArrayCount = 0;

int main()
{
	vector<string> lines = getLinesFromFile(textFileName);
	vector<Contact> contacts = getContactsFromLines(lines);
	getContactsFromVector(contacts);

	bool running = true;
	cout << "***MY PHONEBOOK APPLICATION***" << endl;
	cout << "Please choose an operation:" << endl;
	while (running)
	{
		cout << "A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit): ";
		string word;
		std::getline(cin, word);
		char letter = word[0];
		if(letter == 'A')
		{
			string name, phone;

			cout << "Enter name: ";
			std::getline(cin, name);
			deleteNewLine(name);

			cout << "Enter phone: ";
			std::getline(cin, phone);
			deleteNewLine(phone);

			Contact contact(name, phone);
			arrayContacts[contactsArrayCount] = contact;
			contactsArrayCount++;
		}
		else if(letter == 'S')
		{
			string name;
			cout << "Enter name: ";
			std::getline(cin, name);
			deleteNewLine(name);

			Contact findContact(name);

			for(int i = 0; i < contactsArrayCount; i++)
			{
				Contact contact = arrayContacts[i];
				if(contact == findContact)
				{
					cout << "Phone Number: " << contact.getPhoneNumber() << endl;
					break;
				}
			}
		}
		else if(letter == 'D')
		{
			string name;
			cout << "Enter name: ";
			std::getline(cin, name);
			deleteNewLine(name);
			int i = 0;
			for(; i < contactsArrayCount; i++)
			{
				Contact contact = arrayContacts[i];
				if(contact.getName() == name)
				{
					arrayContacts[i] = arrayContacts[contactsArrayCount - 1];
					contactsArrayCount--;
					break;
				}
			}

		}
		else if(letter == 'L')
		{
			for(int i = 0; i < contactsArrayCount; i++)
			{
				arrayContacts[i].print();
			}
		}
		else if(letter == 'Q')
		{
			running = false;
		}
		else
		{
			cout << "Could not process " << word << ", please enter A, S, D, L, or Q" << endl;
		}
		cout << endl;
	}
	cout << "The program has ended, have a nice day." << endl;

	return 0;
}

vector<string> getLinesFromFile(string location)
{
	vector<string> lines;
	ifstream textFile;
	textFile.open(location);
	if (textFile.is_open())
	{
		string line;
		while (getline(textFile, line, '\n'))
		{
			lines.push_back(line);
		}
	}
	textFile.close();
	return lines;
}

vector<Contact> getContactsFromLines(vector<string> lines)
{
	vector<Contact> contacts;

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		Contact contact(lines[i]);
		contacts.push_back(contact);
	}

	return contacts;
}

void getContactsFromVector(vector<Contact> contacts)
{
	for (unsigned int i = 0; i < contacts.size(); i++)
	{
		arrayContacts[i] = contacts[i];
		contactsArrayCount++;
	}
}
void deleteNewLine(string &line)
{
	line.erase(line.end()-1, line.end());
}
