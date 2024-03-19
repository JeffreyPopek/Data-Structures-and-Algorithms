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

#include <iostream>
#include "Files.h"
#include "timerSystem.h"

using namespace std;

int main()
{
	cout << "Enigma Machine" << info.SPACER;

	Files file;
	Files file2;
	file.ui();

	do
	{
	//Create File one
	file.getWords();

	int NumberTemp = file.countWords();
	string* wordArray = new string[NumberTemp];

	file.splitWords(wordArray);
	file.printWords(wordArray);
	file.encryptFile(wordArray);
	file.makeFile(wordArray);

	//Create File two
	file2.getWords();

	int NumberTemp2 = file2.countWords();
	string* wordArray2 = new string[NumberTemp2];

	file2.splitWords(wordArray2);
	file2.printWords(wordArray2);
	file2.encryptFile(wordArray2);
	file2.makeFile(wordArray2);

	//Compares 2 files
	if (file == file2)
	{
		cout << "You inputed the same you file twice!" << info.SPACER;
	}


	//Delete array, resets counter, and clear string stream
	file.resetCounter();
	file.clearStringStream();
	delete[] wordArray;

	file2.resetCounter();
	file2.clearStringStream();
	delete[] wordArray2;



	} while(file.getChoice() != "exit");



}



