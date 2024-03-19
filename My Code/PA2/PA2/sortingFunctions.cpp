/*
Author: Jeffrey Popek
Class: CSI-281-01: Data Structures & Algorithms
Date Assigned: 9-16-22
Due Date: 9-20-22

Description: Create templates for bubble and insertion sort


Certification of Authenticity: I  certify  that  this  is  entirely  my  own  work,  except  where  I  have  given fully-documented
references  to  the  work  of  others.  I  understand  the definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:-Reproduce  this  assignment  and  provide  a  copy  to  another
member  of academic staff; and/or-Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking service  (which  may  then
retain  a  copy  of  this  assignment  on  its database for the purpose of future plagiarism checking)
*/

#include "sortingFunctions.h"

sortingFunctions::sortingFunctions() = default;


sortingFunctions::~sortingFunctions() = default;


template <typename T>
void sortingFunctions::swap(T* x, T* y)
{
    /*
    Pre: Used in bubble sorting
    Post: Two objects will have their values swapped
    Purpose: Swap function to make bubble sorting easier
    */

    T temp = *x;
    *x = *y;
    *y = temp;
}


template <typename T>
void sortingFunctions::printList(T list[])
{
    /*
    Pre: List created
    Post: Prints list
    Purpose: Prints contents of list
    */

    if (mType == 1)
    {
        for (int i = 0; i < mSize; i++)
        {
            cout << list[i] << "  ";
        }
        cout << endl;
    }
    else if (mType == 2)
    {
        for (int i = 0; i < mSize; i++)
        {
            cout << setprecision(2) << fixed << list[i] << "  ";
        }
        cout << endl;
    }

}


template <typename T>
void sortingFunctions::bubbleSort(T list[])
{
    /*
    Pre: List created
    Post: Sorts list
    Purpose: Bubble sorting function to sort
    */
    int i;
    int j;
    for (i = 0; i < mSize - 1; i++)
    {
        for (j = 0; j < mSize - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                swap(&list[j], &list[j + 1]);
            }
        }
    }
}


template <typename T>
void sortingFunctions::insertionSort(T list[])
{
    /*
    Pre: List created
    Post: List sorted
    Purpose: Insertion sorting function to sort
    */
    int i;
    int j;
    T temp;

    for (i = 1; i < mSize; i++)
    {
        temp = list[i];
        j = i - 1;

        while (j >= 0 && list[j] > temp)
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = temp;
    }
}


void sortingFunctions::UI()
{
    /*
    Pre: None
    Post: UI will be printed, will not exit until user chooses to
    Purpose: Creates list the size that user wants, fills lists with random numbers, calls other functions to make program work
    */


    do {
        mSize = 0;
        do
        {
            cout << SEPERATOR << endl;
            cout << "Enter list size (0 to exit): ";
            cin >> mSize;
            cout << endl;

            if (mSize == 0){ exit(0); }

            if (mSize < 0)
            { 
                cout << "Invalid list size!" << SPACER; 
            }

        } while (mSize < 0);

        int* intList = new int[mSize];
        double* doubleList = new double[mSize];


        //User chooses either bubble or insertion sort
        mChoice = 0;
        do
        {
            cout << "Sorting Method: \n1. Bubble Sort \n2. Insertion Sort \n";
            cin >> mChoice;
            cout << endl;

            if (mChoice != 1 && mChoice != 2)
            { 
                cout << "Invalid sorting method!" << SPACER;
            }

        } while (mChoice != 1 && mChoice != 2);


        //User chooses either int or double list type
        mType = 0;
        do
        {
            cout << "List Type: \n1. Int \n2. Double \n";
            cin >> mType;
            cout << endl;

            if (mType != 1 && mType != 2)
            { 
                cout << "Invalid list type!" << SPACER;
            }

        } while (mType != 1 && mType !=  2);


        srand(time(NULL));


        if (mType == 1)
        {
            //Generates random numbers to put in the list
            for (int i = 0; i < mSize; i++)
            {
                int randomNum = rand() % 100;
                intList[i] = randomNum;
            }

            cout << "Before Sorting: ";
            printList(intList);


            if (mChoice == 1)
            {
                bubbleSort(intList);
            }
            else if (mChoice == 2)
            {
                insertionSort(intList);
            }

            cout << "After Sorting: ";
            printList(intList);
        }
        else if (mType == 2)
        {
            //Generates random numbers to put in the list
            for (int i = 0; i < mSize; i++)
            {
                double randomNum = rand() % 100;
                doubleList[i] = randomNum;
            }

            cout << "Before Sorting: ";
            printList(doubleList);

            if (mChoice == 1)
            {
                bubbleSort(doubleList);
            }
            else if (mChoice == 2)
            {
                insertionSort(doubleList);
            }


            cout << "After Sorting: ";
            printList(doubleList);
        }

        delete[] intList;
        delete[] doubleList;
    } while (mSize != 0);
}






