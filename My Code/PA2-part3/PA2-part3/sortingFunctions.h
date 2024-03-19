/*
Author: Jeffrey Popek
Class: CSI-281-01: Data Structures & Algorithms
Date Assigned: 9-27-22
Due Date: 10-4-22

Description: Mostly just stub driver


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


using namespace std;

const string SEPERATOR = "---------------------------------------------------------------------------------------------------------";
const string SPACER = "\n\n";



//Functions to help sorting methods
template <typename T>
void fillList(T list[], long size)
/*
    Pre: None
    Post: List filled with random numbers
    Purpose: Needed to create array with random numbers
*/
{
    srand(time(NULL));

    for (long i = 0; i < size; i++)
    {
        long random = rand() % 100000 + 1;
        list[i] = random;
    }
}


template <typename T>
void flipList(T list[], long size)
{
    /*
    Pre: List sorted in best case
    Post: List flipped into worse case
    Purpose: To sort list in worse case
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
T getMax(T list[])
{
    /*
    Pre: List created
    Post: gets max value from list
    Purpose: Helps sorting by finding max value in the list
    */

    int size = sizeof(list) + 1;
    T max = list[1];
    for (int i = 2; i <= size; i++) {
        if (list[i] > max)
            max = list[i];
    }
    return max;
}


template <typename T>
void merge(T list[], long lowerBound, long middle, long upperBound)
{
    /*
    Pre: List created
    Post: List mostly sorted
    Purpose: Helps sort and does most of the hard work
    */

    long i, j, k;

    long sizeOne = middle - lowerBound + 1;
    long sizeTwo = upperBound - middle;

    T* tempArrayOne = new T[sizeOne];
    T* tempArrayTwo = new T[sizeTwo];

    for (i = 0; i < sizeOne; i++)
    {
        tempArrayOne[i] = list[lowerBound + i];
    }

    for (j = 0; j < sizeTwo; j++)
    {
        tempArrayTwo[j] = list[middle + j + 1];
    }

    i = 0;
    j = 0;

    for (k = lowerBound; k <= upperBound && i < sizeOne && j < sizeTwo; k++)
    {
        if (tempArrayOne[i] <= tempArrayTwo[i])
        {
            list[k] = tempArrayOne[i];
            i++;
        }
        else
        {
            list[k] = tempArrayTwo[j];
            j++;
        }
    }

    while(i < sizeOne)
    {
        list[k] = tempArrayOne[i];
        i++;
        k++;
    }

    while (j < sizeTwo)
    {
        list[k] = tempArrayTwo[j];
        j++;
        k++;
    }

    delete[] tempArrayOne;
    delete[] tempArrayTwo;
}


template <typename T>
int partition(T list[], long lowerBound, long upperBound)
{
    /*
    Pre: List created
    Post: Pivot returned
    Purpose: Finds pivot point in the list
    */
    T pivot = list[lowerBound];

    long count = 0;
    for (long i = lowerBound + 1; i <= upperBound; i++) {
        if (list[i] <= pivot)
            count++;
    }

    long pivotPoint = lowerBound + count;
    swap(list[pivotPoint], list[lowerBound]);


    long i = lowerBound;
    long j = upperBound;


    while (i < pivotPoint && j > pivotPoint) {

        while (list[i] <= pivot) {
            i++;
        }

        while (list[j] > pivot) {
            j--;
        }

        if (i < pivotPoint && j > pivotPoint) {
            swap(list[i++], list[j--]);
        }
    }

    return pivotPoint;
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



//Sorting Functions
template <typename T>
void bubbleSort(T list[], int size)
{
    /*
    Pre: List created
    Post: Sorts list
    Purpose: Bubble sorting function for assignment (PA-part1)
    */
    int i;
    int j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                swap(&list[j], &list[j + 1]);
            }
        }
    }
}


template <typename T>
void cocktailSort(T list[], int size)
{
    /*
    Pre: List created
    Post: List sorted
    Purpose: Cocktail sorting function for assignment (PA-part2)
    Explanation: This is one sorting method not covered in class, it is similar to bubble sort.
    */

    bool swapped = true;
    int start = 0;
    int end = size - 1;
    int i;

    while (swapped)
    {
        swapped = false;

        for (i = start; i < end; ++i)
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

        for (i = end - 1; i >= start; --i)
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


template <typename T>
void insertionSort(T list[], int size)
{
    /*
    Pre: List created
    Post: List sorted
    Purpose: Insertion sorting function for assignment (PA-part 1)
    */
    int i;
    int j;
    T temp;


    for (i = 1; i < size; i++)
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


template <typename T>
void mergeSort(T list[], long lowerBound, long upperBound)
{
    /*
    Pre: List created
    Post: Sorts list
    Purpose: Merge sort function for assignment (PA-part3)
    */
    
    long middle;

    if (lowerBound < upperBound)
    {
        middle = (lowerBound + upperBound) / 2;

        mergeSort(list, lowerBound, middle);
        mergeSort(list, middle + 1, upperBound);

        merge(list, lowerBound, middle, upperBound);
    }
}


template <typename T>
void quickSort(T list[], long lowerBound, long upperBound)
{
    /*
    Pre: List created
    Post: Sorts list
    Purpose: Quick sort function for assignment (PA-part3)
    */
    long i = lowerBound;
    long j = upperBound;
    T pivot = list[(lowerBound + upperBound) / 2];

    while (i <= j)
    {
        while (list[i] < pivot)
        {
            i++;
        }

        while (list[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(list[i], list[j]);
            i++;
            j--;
        }

    }

    if (lowerBound < j)
    {
        quickSort(list, lowerBound, j);
    }

    if (i < upperBound)
    {
        quickSort(list, i, upperBound);
    }


}


template <typename T>
void selectionSort(T list[], int size)
{
    /*
    Pre: List created
    Post: Sorts list
    Purpose: Selection sorting function for assignment (PA-part2)
    */

    int i, j, minIndex;


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
void shellSort(T list[], int size)
{
    /*
    Pre: List created
    Post: List sorted
    Purpose: Shell sorting function for assignment (PA-part2)
    */

    long i;
    long gap = size / 2;
     while(gap > 0)
     {
         for (i = 1; i < size - gap; i++)
         {
             if (list[i] > list[i + gap])
             {
                 swap(list[i], list[i + gap]);
             }
         }

         gap = gap / 2;
     }

     bubbleSort(list, size);

}