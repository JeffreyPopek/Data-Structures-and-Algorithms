/*
Author: Jeffrey Popek
Class: CSI-281-01: Data Structures & Algorithms
Date Assigned: 9-20-22
Due Date: 9-23-22

Description: Create templates for selection and shell sort
z

Certification of Authenticity: I  certify  that  this  is  entirely  my  own  work,  except  where  I  have  given fully-documented
references  to  the  work  of  others.  I  understand  the definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:-Reproduce  this  assignment  and  provide  a  copy  to  another
member  of academic staff; and/or-Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking service  (which  may  then
retain  a  copy  of  this  assignment  on  its database for the purpose of future plagiarism checking)
*/

#include <iostream>
#include <iomanip>
#include "sortingFunctions.h"

using namespace std;


int main()
{
    //Selection
    int selectionIntArray[] = { 77, 54, 7, 62, 14 };
    double selectionDoubleArray[] = { 6.43, 88.92, 43.36, 9.42, 1.41 };


    cout << SEPERATOR << endl << "Selection Sort" << SPACER;

    cout << "Int array before sorting: ";
    printList(selectionIntArray);

    cout << "Double array before sorting: ";
    printList(selectionDoubleArray);


    selectionSort(selectionIntArray);
    selectionSort(selectionDoubleArray);


    cout << "Int array after sorting: ";
    printList(selectionIntArray);

    cout << "Double array after sorting: ";
    printList(selectionDoubleArray);


    //Shell
    int shellIntArray[] = { 234, 4, 66, 19, 2 };
    double shellDoubleArray[] = { 88.53, 345.11, 56.24, 1.11, 0.14 };


    cout << SEPERATOR << endl << "Shell Sort" << SPACER;


    cout << "Int array before sorting: ";
    printList(shellIntArray);

    cout << "Double array before sorting: ";
    printList(shellDoubleArray);


    shellSort(shellIntArray);
    shellSort(shellDoubleArray);


    cout << "Int array after sorting: ";
    printList(shellIntArray);

    cout << "Double array after sorting: ";
    printList(shellDoubleArray);


    //Cocktail
    int cocktailIntArray[] = { 213, 22, 624, 9, 21 };
    double cocktailDoubleArray[] = { 56.11, 2.77, 0.77, 66.97, 9.40 };


    cout << SEPERATOR << endl << "Cocktail Sort" << SPACER;


    cout << "Int array before sorting: ";
    printList(cocktailIntArray);

    cout << "Double array before sorting: ";
    printList(cocktailDoubleArray);


    cocktailSort(cocktailIntArray);
    cocktailSort(cocktailDoubleArray);


    cout << "Int array after sorting: ";
    printList(cocktailIntArray);

    cout << "Double array after sorting: ";
    printList(cocktailDoubleArray);

    cout << SEPERATOR;
}



