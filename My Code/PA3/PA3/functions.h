#pragma once
/*
Author: Jeffrey Popek
Class: CSI-281-01: Data Structures & Algorithms
Date Assigned: 10-7-22
Due Date: 10-21-22

Description: Have template functions for searching algorithms and test them


Certification of Authenticity: I  certify  that  this  is  entirely  my  own  work,  except  where  I  have  given fully-documented
references  to  the  work  of  others.  I  understand  the definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:-Reproduce  this  assignment  and  provide  a  copy  to  another
member  of academic staff; and/or-Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking service  (which  may  then
retain  a  copy  of  this  assignment  on  its database for the purpose of future plagiarism checking)
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <time.h>
#include <random>
#include <algorithm> 


using namespace std;

const string SEPERATOR = "---------------------------------------------------------------------------------------------------------";
const string SPACER = "\n\n";


//Functions to help sorting methods
template <typename T>
void fillList(T list[], long size)
/*
    Pre: None
    Post: List filled with numbers
    Purpose: Needed to create array with random numbers
*/
{
    for (long i = 0; i < size; i++)
    {
        list[i] = i;
    }
}


template <typename T>
void fillListMidpoint(T list[], long size, T searchKey)
/*
    Pre: None
    Post: List filled with numbers and put your searchkey in the middle
    Purpose: Needed to create array with numbers and searchkey in the middle for best case
*/
{
    long mid = size / 2;

    for (long i = 1; i < size; i++)
    {
        if (i == mid)
        {
            list[i] = searchKey;
        }
        else
        {
            list[i] = i;
        }
    }
}


template <typename T>
void flipList(T list[], long size)
{
    /*
    Pre: List sorted in best case
    Post: List flipped
    Purpose: list to be in worse case
    */
    long i;
    long j = size - 1;
    for (i = 0; i < size / 2; i++)
    {
        T temp = list[i];
        list[i] = list[j];
        list[j] = temp;
        j--;
    }
}


template <typename T>
void printList(T list[], int size)
{
    /*
    Pre: List created
    Post: Prints list
    Purpose: Prints contents of list
    */

    for (int i = 0; i < size; i++)
    {
        cout << fixed << setw(8) << setprecision(2) << list[i] << "  ";
    }
    cout << SPACER;
}


template <typename T>
void shuffleList(T list[], int size)
{
    /*
    Pre: List created
    Post: Shuffles list randomly
    Purpose: shuffles list for average case search
    */
    srand(time(0));

    random_shuffle(list, list + size);
}

template <typename T>
void swap(T* x, T* y)
{
    /*
    Pre: None
    Post: Two values swapped
    Purpose: Helps with sorting
    */

    T temp = *x;
    *x = *y;
    *y = temp;
}


template <typename T>
bool sequentialSearch(T list[], int size, T searchKey)
{
    /*
    Pre: List created
    Post: sequential search through list and returns bool for searchkey
    Purpose: Searches for searchkey
    */
    int i;
    for (i = 0; i < size; i++)
    {
        if (list[i] == searchKey)
        {
            return true;
        }
    }
        
    return false;
}


template <typename T>
bool enchancedSequentialSearch(T list[], int size, T searchKey)
{
    /*
    Pre: List created
    Post: sequential search through list and returns bool for searchkey
    Purpose: Searches for searchkey, checks if value is larger then searchkey, if so exits
    */
    int i;
    for (i = 0; i < size; i++)
    {
        if (list[i] == searchKey)
        {
            return true;
        }
        else if (list[i] > searchKey)
        {
            break;
        }
    }

    return false;
}


template <typename T>
bool binarySearch(T list[], long lowerBound, long upperBound, T searchKey)
{
    /*
    Pre: List created
    Post: binary search through list and uses midpoints to find searchkey
    Purpose: Searches for searchkey 
    */
    while (lowerBound <= upperBound)
    {
        long mid = (lowerBound + upperBound) / 2;

        if (list[mid] = searchKey)
        {
            return true;
        }
        else if (list[mid] > searchKey)
        {
            upperBound = mid - 1;
        }
        else
        {
            lowerBound = mid + 1;
        }
    }

    return false;
}