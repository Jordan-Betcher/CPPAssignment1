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
void deleteNewLine(string &line);
//test
string textFileName = "phonebook.txt";

int main()
{
	vector<string> lines = getLinesFromFile(textFileName);
	vector<Contact> contacts = getContactsFromLines(lines);

	bool running = true;
	cout << "Please type one of the following" << endl;
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
			contacts.push_back(contact);
		}
		else if(letter == 'S')
		{
			string name;
			cout << "Enter name: ";
			std::getline(cin, name);
			deleteNewLine(name);

			for(int i = 0; i < contacts.size(); i++)
			{
				Contact contact = contacts[i];
				if(contact.getName() == name)
				{
					contact.print();
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
			for(; i < contacts.size(); i++)
			{
				Contact contact = contacts[i];
				if(contact.getName() == name)
				{
					break;
				}
			}
			contacts.erase(contacts.begin() + i);

		}
		else if(letter == 'L')
		{
			for(int i = 0; i < contacts.size(); i++)
			{
				contacts[i].print();
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

void deleteNewLine(string &line)
{
	line.erase(line.end()-1, line.end());
}
