/*
Author: Jeffrey Popek
Class: CSI-281-01: Data Structures & Algorithms
Date Assigned: 11-29-22
Due Date: 12-9-22

Description: Final project is to make PA1 encryption time 50% faster


Certification of Authenticity: I  certify  that  this  is  entirely  my  own  work,  except  where  I  have  given fully-documented
references  to  the  work  of  others.  I  understand  the definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:-Reproduce  this  assignment  and  provide  a  copy  to  another
member  of academic staff; and/or-Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking service  (which  may  then
retain  a  copy  of  this  assignment  on  its database for the purpose of future plagiarism checking)
*/

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "timerSystem.h"

using namespace std;

struct Utilities
{
	const string CODE_FILE_PATH = "codes.txt";
	const string WORD_FILE_PATH = "words.txt";
	const string ENCRYPTED_FILE_TAG = "(ENCRYPTED)";
	const string ENCRYPTED_FILE_PATH = "ENCRYPTED/";
	const string SPACER = "\n\n";
} utilities;


class Functions
{
private:
	void createFile();
	void encrpyt();
	void getWords();
	void printList();

	vector<string> mList;

public:
	void UI();
};



/*
	Pre: List filled
	Post: Puts contents of list into a file, if file doesn't exist it creates one
	Purpose: Needed to save the code created my the enigma machine
*/
void Functions::createFile()
{
	ofstream fout(utilities.ENCRYPTED_FILE_PATH + utilities.ENCRYPTED_FILE_TAG + utilities.WORD_FILE_PATH);

	//Puts contents of array into new file
	for (int i = 0; i < mList.size(); i++)
	{
		fout << mList[i] + ' ';
	}

	cout << "New file created named: (ENCRYPTED)" + utilities.WORD_FILE_PATH << utilities.SPACER;
	fout.close();
}


/*
	Pre: Words in list
	Post: Replaces the words that can be encrypted with their corresponding codes
	Purpose: Encrypts word.txt file with the codes in the code.txt file.
*/
void Functions::encrpyt()
{
	TimerSystem timer;
	ifstream inputFin(utilities.CODE_FILE_PATH);

	if (inputFin.fail())
	{
		cout << "File not found";
		exit(0);
	}
	
	printList();


	timer.startClock();

	int counter = 0;
	int i;

	do
	{
		while (!inputFin.eof())
		{
			string tempWord = "";
			string tempCode = "";

			inputFin >> tempWord;
			inputFin >> tempCode;

			for (i = 0; i <= (mList.size() - 1); i++)
			{
				if (tempWord == mList[i]) {
					mList[i] = tempCode;
					counter++; 
				}
			}
		}
	} while (counter != (mList.size() - 1));
	

	cout << "Time: " << timer.getTime() << endl;
	printList();
}


/*
	Pre: None
	Post: Words from words.txt will be in a list
	Purpose: Gets words from the text file and puts them into a vector
*/
void Functions::getWords()
{
	cout << endl << "Using file: " << utilities.WORD_FILE_PATH << endl;

	int i;
	ifstream inputFin(utilities.WORD_FILE_PATH);

	if (inputFin.fail())
	{
		cout << "File not found";
		exit(0);
	}

	while (!inputFin.eof())
	{
		string junk, temp;

		getline(inputFin, junk);

		int length = junk.length();

		for (i = 0; i < length; i++)
		{

			if (junk[i] == ' ')
			{
				mList.push_back(temp);
				temp = "";
			}
			else
			{
				temp += junk[i];
			}
		}
		//gets last word in vector
		mList.push_back(temp);
	}
}


/*
	Pre: List created
	Post: List will be printed
	Purpose: To show the list before and after the encryption process
*/
void Functions::printList()
{
	cout << endl << "Your List: ";

	for (int i = 0; i < mList.size(); i++)
	{
		cout << mList[i] << " ";
	}

	cout << utilities.SPACER;
}


/*
	Pre: None
	Post: UI will be shown and all the previous functions are called 
	Purpose: To make the program look nicer and to have somewhere to call each function
*/
void Functions::UI()
{
	cout << "ENIGMA MACHINE" << utilities.SPACER;

	int choice;
	do
	{
		cout << "1. Encrypt" << endl << "2. Exit" << endl;

		cin >> choice;

		switch (choice) {
		case 1:
			break;
		case 2:
			cout << "Exiting" << endl;
			exit(0);
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (choice != 1);


	getWords();
	encrpyt();
	createFile();
}
