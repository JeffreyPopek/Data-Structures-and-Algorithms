/*
Author: Saruman
Class: CSI-281-01: Data Structures & Algorithms
Date Assigned: 8-30-22
Due Date: 9-6-22

Description: Create an Enigma Machine that encrypts a user inputed file


Certification of Authenticity: I  certify  that  this  is  entirely  my  own  work,  except  where  I  have  given fully-documented
references  to  the  work  of  others.  I  understand  the definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:-Reproduce  this  assignment  and  provide  a  copy  to  another
member  of academic staff; and/or-Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking service  (which  may  then
retain  a  copy  of  this  assignment  on  its database for the purpose of future plagiarism checking)
*/

#include"Files.h"
#include "timerSystem.h"

Files::Files() = default;

Files::~Files() = default;

void Files::ui() {
	/*
	Pre: None
	Post: UI displayed on screen
	Purpose: Interface to exit to start the program
	*/
	int choice;
	do
	{
		cout << "1. Encrypt Document" << endl << "2. Exit" << endl;

		cin >> choice;

		switch (choice) {
		case 1:
			break;
		case 2:
			cout << "Thanks for using" << endl;
			exit(0);
		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	} while (choice != 1);
	
}

void Files::getWords()
{
	/*
	Pre: File object created
	Post: Get words from file into string stream
	Purpose: To get info from file into a string stream
	*/
	
	cout << info.SEPERATOR << endl;

	cout << "Enter input file's name (do not include .txt), type exit to exit" << endl;
	cin >> mChoice;
	if (mChoice == "exit")
	{
		exit(0);
	}


	//Open your input file
	ifstream inputFin(mChoice + info.WORD_FILE_TYPE);
	if (inputFin.fail())
	{
		cout << "File could not be opened...";
		exit(0);
	}	
	

	//Gets all words into the string stream
	while (!inputFin.eof())
	{
		string junk = "";

		getline(inputFin, junk);

		mSS << junk << " ";
	}
}

int Files::countWords()
{
	/*
	Pre: Words in string stream
	Post: Returns number of words in string stream
	Purpose: Counts words in the string stream for other functions
	*/

	string temp = mSS.str();
	int length = temp.size();

	for (int i = 0; i < length; i++)
	{
		if (temp[i] == ' ')
		{
			mCounter++;
		}
	}
	cout << info.SPACER << "Words in file: " << mCounter << endl;

	return mCounter;
}

void Files::splitWords(string* array)
{
	/*
	Pre: Words in string stream
	Post: Words individually in dynamic array
	Purpose: Splits words in string stream and puts them into a dynamic array
	*/

	string temp = mSS.str();
	istringstream input(temp);
	string word;

	for (int i = 0; i < mCounter; i++)
	{
		input >> word;
		array[i] = word;
	}
}

void Files::printWords(string* array)
{
	/*
	Pre: Words in array
	Post: Prints array contents
	Purpose: Shows user the array contents
	*/

	for (int i = 0; i < mCounter; i++)
	{
		cout << array[i] + ' ';
	}

	cout << info.SPACER;
}

void Files::encryptFile(string* array)
{
	/*
	Pre: Words in array
	Post: Encrypts words and replaces the encrypted words with their code
	Purpose: Turn words into their code pair, if not word doesn't change
	*/

	TimerSystem timer;

	int counter = 1;
	timer.startClock();

	int i = 0;

	cout << "Searching codebook for your words... This may take a while" << endl;
	do {
		string wordToFind = array[i];

		//Open code book 
		ifstream codebookFin(info.CODEBOOK_FILE_PATH);
		if (codebookFin.fail())
		{
			cout << "File could not be opened...";
			break;
		}

		while (!codebookFin.eof())
		{
			string tempWord = "";
			string tempCode = "";

			codebookFin >> tempWord;
			codebookFin >> tempCode;

			//When you find your codepair it breaks out of loop
			if (tempWord == wordToFind) {
				array[i] = tempCode;
				break;
			}
		}

		//Look for the next word in the array
		i++;
		codebookFin.close();

	} while (i != mCounter);

	cout << "Encryption time for test " << counter << ": " << timer.getTime() << "s\n";
	counter++;
}

void Files::makeFile(string* array)
{
	/*
	Pre: Code/words in array
	Post: New file with code and words
	Purpose: Gets output file name and puts the array contents on to the new file
	*/

	cout << "Name encrypted output file: ";
	cin >> mEncryptedFileName;

	ofstream fout(info.ENCRYPTED_FILE_PATH + mEncryptedFileName + info.ENCRYPTED_FILE_TAG + info.WORD_FILE_TYPE);

	//Puts contents of array into new file
	for (int i = 0; i < mCounter; i++)
	{
		fout << array[i] + ' ';
	}

	cout << info.SPACER << "New file created named: ENCRYPTED-" + mEncryptedFileName << info.SPACER;
	fout.close();
}

void Files::resetCounter()
{
	/*
	Pre: none
	Post: Counter is set to zero
	Purpose: Sets member variable, mCounter, to zero
	*/
	mCounter = 0;
}

string Files::getChoice()
{
	/*
	Pre: none
	Post: User's choice will be returned
	Purpose: Returns member variable, mChoice, for the main
	*/
	return mChoice;
}

void Files::clearStringStream()
{
	/*
	Pre: none
	Post: String stream will be empty
	Purpose: Clears string stream so program and run again clean
	*/
	mSS.str("");
}

bool Files::operator==(const Files& file)
{	
	/*
	Pre: File objects created
	Post: Compares two files and returns true or false
	Purpose: Checks if two inputed files are the same
	*/
	bool sameFile = false;
	if (this->mCounter == file.mCounter)
	{
		if (this->mSS.str() == file.mSS.str())
		{
			sameFile = true;
		}
	}
	return sameFile;
}