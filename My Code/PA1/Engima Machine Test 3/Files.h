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

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>


using namespace std;

struct
{
	const string CODEBOOK_FILE_PATH = "codes.txt";
	const string ENCRYPTED_FILE_TAG = "-ENCRYPTED";
	const string ENCRYPTED_FILE_PATH = "ENCRYPTED/";
	const string WORD_FILE_TYPE = ".txt";
	const string SPACER = "\n\n";
	const string SEPERATOR = "---------------------------------------------";
} info;

class Files
{
public:
	Files();

	~Files();

	void ui();

	void getWords();

	int countWords();

	void splitWords(string* array);

	void printWords(string* array);

	void encryptFile(string* array);

	void makeFile(string* array);

	void resetCounter();

	string getChoice();

	void clearStringStream();

	bool operator== (const Files& file);

private:
	string mChoice = "";
	string mEncryptedFileName = "";
	int mCounter = 0;
	stringstream mSS;
};