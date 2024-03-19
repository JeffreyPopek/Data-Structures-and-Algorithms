/*
Author: Jeffrey Popek
Class: CSI-281-01: Data Structures & Algorithms
Date Assigned: 11-4-22
Due Date: 11-11-22

Description: Create binary search and test in a doubly linked list, then write a report based on the results


Certification of Authenticity: I  certify  that  this  is  entirely  my  own  work,  except  where  I  have  given fully-documented
references  to  the  work  of  others.  I  understand  the definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:-Reproduce  this  assignment  and  provide  a  copy  to  another
member  of academic staff; and/or-Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking service  (which  may  then
retain  a  copy  of  this  assignment  on  its database for the purpose of future plagiarism checking)
*/

#include <iostream>
#include "doublyLinkedList.h"
#include "timerSystem.h"

using namespace std;


int main()
{
    DoublyLinkedList<int>* list;
    TimerSystem timer;
    int i;

    int size = 1000;
    int* arr = new int[size];

    list = new DoublyLinkedList<int>;

 
    generateList(arr, size);
    bubbleSort(arr, size);


    for (i = 0; i <= size - 1; i++)
    {
        list->insert(arr[i]);
    }

    cout << "Sorted list of random numbers: " << endl;
    list->display();
    cout << endl;


    //Use this to generate numbers not in the main list
    //int* invalidList = new int[10];
    //generateInvalidNums(invalidList, arr, 10);


    //change i to what number you want to start on
    int searchKey;
    for (int i = 0; i < 10; i++)
    {
        //Replace arr with invalidList to test invalid nums
        searchKey = arr[i];
        timer.startClock();

        cout << "Searching for: " << searchKey << endl;

        list->isExistBinary(searchKey);
        //list->isExist(searchKey);

        cout << "Time: " << timer.getTime() << "s\n" << endl;
    }


    delete[] arr;
    delete list;

    system("pause");

    return 0;
}