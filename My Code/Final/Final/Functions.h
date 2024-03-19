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
#include <fstream>
#include "timerSystem.h"

using namespace std;


struct Utilities
{
    const string CODE_FILE_PATH = "codes.txt";
    const string WORD_FILE_PATH = "words.txt";
    const string ENCRYPTED_FILE_TAG = "(ENCRYPTED)";
    const string ENCRYPTED_FILE_PATH = "ENCRYPTED/";
    const string SPACER = "\n\n";
    const int ARR_INFO = 2;
    const int WORD_AMOUNT = 398484;
} utilities;


struct Word
{
    Word(string word, Word* next = nullptr)
    {
        this->mWord = word;
        this->mNext = next;
    }

    string mWord;
    Word* mNext;
};

class Functions
{
private:
    void cleanUp();
    void encrypt(Word*& word);
    void getWords();
    void quickSort(int lowerBound, int upperBound);
    string searchList(string searchKey, int lowerBound, int upperBound);

    string** mList;
    Word* mWordsList;
    int mCounter;

public:
    void UI();
};


//private functions
void Functions::cleanUp()
{
    /*
    Pre: List created
    Post: Deletes pointers
    Purpose: Deletes lists so no memory leaks
    */
    Word* wordsNext;

    //clears list
    while (mWordsList != nullptr)
    {
        wordsNext = mWordsList->mNext;
        delete mWordsList;
        mWordsList = wordsNext;
    }

    mWordsList, wordsNext = nullptr;

    int i;
    for (i = 0; i < utilities.WORD_AMOUNT; i++)
    {
        delete[] mList[i];
    }

    delete[] mList;
    mList = nullptr;
}

void Functions::encrypt(Word*& word)
{
    /*
    Pre: List and sorted
    Post: Encrypts list and puts it in a new file (creates one if not found)
    Purpose: Use code file to turn given list of words into code
    */
    ofstream fout(utilities.ENCRYPTED_FILE_PATH + utilities.ENCRYPTED_FILE_TAG + utilities.WORD_FILE_PATH);

    while (word != nullptr)
    {
        //finds matching code in list
        string temp = searchList(word->mWord, 0, utilities.WORD_AMOUNT - 1);

        if (temp == "not found")
        {
            fout << word->mWord << " ";
        }
        else
        {
            fout << temp << " ";
        }

        word = word->mNext;
    }
}

void Functions::getWords()
{
    /*
    Pre: None
    Post: Both lists filled with words and codes
    Purpose: Used to fill lists from txt files
    */
    mWordsList = nullptr;
    mCounter = 0;

    mList = new string* [utilities.WORD_AMOUNT];
    for (int i = 0; i < utilities.WORD_AMOUNT; i++)
    {
        mList[i] = new string[utilities.ARR_INFO];
    }

    //open words.txt
    ifstream fin(utilities.WORD_FILE_PATH);

    //check if file exists
    if(fin.fail())
    {
        cout << utilities.WORD_FILE_PATH << " not found, exiting..." << endl;
        exit(0);
    }

    //puts words into words arr
    while (!fin.eof())
    {
        string input = "";
        fin >> input;

        mWordsList = new Word(input, mWordsList);
        mCounter++;
    }

    //opens codes.txt
    ifstream finTwo(utilities.CODE_FILE_PATH);

    //check if file exists
    if (finTwo.fail())
    {
        cout << utilities.CODE_FILE_PATH << " not found, exiting..." << endl;
        exit(0);
    }

    int counter = 0;
    while (!finTwo.eof())
    {
        string word = "";
        string code = "";

        finTwo >> word;
        finTwo >> code;

        if (counter < utilities.WORD_AMOUNT)
        {
            mList[counter][0] = word;
            mList[counter][1] = code;
        }

        counter++;
    }

    quickSort(0, utilities.WORD_AMOUNT - 1);
}

void Functions::quickSort(int lowerBound, int upperBound)
{
    /*
    Pre: List created
    Post: Sorts list
    Purpose: Fastest sorting algo, used
    */
    long i = lowerBound;
    long j = upperBound;
    string p = mList[(lowerBound + upperBound) / 2][0];

    while (i <= j)
    {
        while (mList[i][0] < p)
        {
            i++;
        }
        while (mList[j][0] > p)
        {
            j--;
        }

        if (i <= j)
        {
            swap(mList[i][0], mList[j][0]);
            swap(mList[i][1], mList[j][1]);
            i++;
            j--;
        }
    }

    if (lowerBound < j)
    {
        quickSort(lowerBound, j);
    }

    if (i < upperBound)
    {
        quickSort(i, upperBound);
    }
}

string Functions::searchList(string searchKey, int lowerBound, int upperBound)
{
    /*
    Pre: List created
    Post: Returns a value from list if found
    Purpose: To determine whether a search key exists in the list
    */
    int middle;

    while (lowerBound <= upperBound)
    {
        middle = (lowerBound + upperBound) / 2;
        if (mList[middle][0] == searchKey)
        {
            return mList[middle][1];
        }
        else if (mList[middle][0] > searchKey)
        {
            upperBound = middle - 1;
        }
        else
        {
            lowerBound = middle + 1;
        }
    }

    return "not found";
}


//public functions
void Functions::UI()
{
    /*
    Pre: None
    Post: UI will be shown and all the previous functions are called
    Purpose: To make the program look nicer and to have somewhere to call each function
    */
    TimerSystem timer;

    cout << "Enigma Machine" << utilities.SPACER;

    cout << "Getting words..." << utilities.SPACER;
    getWords();

    timer.startClock();

    cout << "Encrypting..." << utilities.SPACER;
    encrypt(mWordsList);

    cout << "Time: " << timer.getTime() << endl;

    cleanUp();
}