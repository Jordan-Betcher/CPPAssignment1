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
#include "Person.h"

using namespace std;

vector<string> getLinesFromFile(string location);
vector<Person> getPersonsFromLines(vector<string> lines);

string textFileName = "phonebook.txt";

int main()
{
	vector<string> lines = getLinesFromFile(textFileName);
	vector<Person> persons = getPersonsFromLines(lines);

	bool running = true;
	cout << "Please type one of the following" << endl;
	while (running)
	{
		string name, phone;
		cout << "A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit): ";
		char test;
		cin >> test;
		switch (test)
		{
			case 'Q':
				running = false;
				break;
			case 'A':
				cout << "Enter name: ";
				cin >> name;
				cout << "Enter phone: ";
				cin >> phone;

				cout << name + " " + phone << " has been stored in the vector"
				        << endl;
				break;

			case 'S':
			case 'D':
			case 'L':
			default:
				cout
				        << "Sorry, we weren't able to process your request, please try again"
				        << endl;

		}
	}
	cout << "The program has ended, have a nice day.";

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

vector<Person> getPersonsFromLines(vector<string> lines)
{
	vector<Person> persons;

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		Person person(lines[i]);
		persons.push_back(person);
	}

	return persons;
}
