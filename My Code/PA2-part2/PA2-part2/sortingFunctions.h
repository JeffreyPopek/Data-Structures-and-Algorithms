/*
Author: Jeffrey Popek
Class: CSI-281-01: Data Structures & Algorithms
Date Assigned: 9-20-22
Due Date: 9-23-22

Description: Create templates for selection and shell sort


Certification of Authenticity: I  certify  that  this  is  entirely  my  own  work,  except  where  I  have  given fully-documented
references  to  the  work  of  others.  I  understand  the definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:-Reproduce  this  assignment  and  provide  a  copy  to  another
member  of academic staff; and/or-Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking service  (which  may  then
retain  a  copy  of  this  assignment  on  its database for the purpose of future plagiarism checking)
*/

#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

const string SEPERATOR = "---------------------------------------------------------------------------------------------------------";
const string SPACER = "\n\n";


template <typename T>
void swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}


template <typename T>
T getMax(T list[]) 
{
    int size = sizeof(list) + 1;
    T max = list[1];
    for (int i = 2; i <= size; i++) {
        if (list[i] > max)
            max = list[i];
    }
    return max;
}


template <typename T>
void printList(T list[])
{
        /*
        Pre: List created
        Post: Prints list
        Purpose: Prints contents of list
        */

        for (int i = 0; i <= sizeof(list); i++)
        {
            cout << fixed << setw(8) << setprecision(2) << list[i] << "  ";
        }
        cout << SPACER;
}


template <typename T>
void selectionSort(T list[])
{
    /*
    Pre: List created
    Post: Sorts list
    Purpose: Selection sorting function to sort
    */

    int i, j, minIndex;

    int size = sizeof(list) + 1;

    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++)
            if (list[j] < list[minIndex])
                minIndex = j;

        if (minIndex != i)
        {
            swap(&list[minIndex], &list[i]);
        }
    }
}


template <typename T>
void shellSort(T list[])
{
   /*
   Pre: List created
   Post: List sorted
   Purpose: Shell sorting function to sort
   */

    int size = sizeof(list) + 1;
   
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1)
        {
            T temp = list[i];

            int j;

            for (j = i; j >= gap && list[j - gap] > temp; j -= gap)
            {
                list[j] = list[j - gap];
            }

            list[j] = temp;
        }
    }

}


template <typename T>
void cocktailSort(T list[])
{
   /*
   Pre: List created
   Post: List sorted
   Purpose: Cocktail sorting function to sort
   Explanation: This is one sorting method not covered in class, it is similar to bubble sort.
   */

    bool swapped = true;
    int start = 0;
    int size = sizeof(list) + 1;
    int end = size - 1;
    
    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) 
        {
            if (list[i] > list[i + 1]) 
            {
                swap(list[i], list[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;

        --end;

        for (int i = end - 1; i >= start; --i) 
        {
            if (list[i] > list[i + 1]) 
            {
                swap(list[i], list[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}