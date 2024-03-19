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

#include <iostream>
#include <iomanip>
#include <time.h>
#include "functions.h"
#include "timerSystem.h"

using namespace std;
int main()
{
    TimerSystem timer;

    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(16);

    int sizeOne = 100;
    int sizeTwo = 10000;
    int sizeThree = 1000000;

    int searchKey = 0;

    //Sequential Search (100)
    {
        cout << "Sequential Search (100)" << endl;

        int* sequentialArray = new int[sizeOne];
        
        //Have list in order for best case
        fillList(sequentialArray, sizeOne);

        //printList(sequentialArray, sizeOne);

    
        timer.startClock();

        enchancedSequentialSearch(sequentialArray, sizeOne, searchKey);

        cout << "BC " << timer.getTime() << "s\n";
 


        //Flip list for worse case
        flipList(sequentialArray, sizeOne);

        timer.startClock();

        sequentialSearch(sequentialArray, sizeOne, searchKey);

        cout << "WC " << timer.getTime() << "s\n";
    


        //Have list be random for average case
        shuffleList(sequentialArray, sizeOne);
    
        timer.startClock();

        sequentialSearch(sequentialArray, sizeOne, searchKey);

        cout << "AC " << timer.getTime() << "s\n";
    

    
        delete[] sequentialArray;
    }

    cout << SPACER;

    //Sequential Search (10000)
    {
        cout << "Sequential Search (10000)" << endl;

        int* sequentialArray = new int[sizeTwo];

        //Have list in order for best case
        fillList(sequentialArray, sizeTwo);

        //printList(sequentialArray, sizeOne);


        timer.startClock();

        enchancedSequentialSearch(sequentialArray, sizeTwo, searchKey);

        cout << "BC " << timer.getTime() << "s\n";



        //Flip list for worse case
        flipList(sequentialArray, sizeTwo);

        timer.startClock();

        sequentialSearch(sequentialArray, sizeTwo, searchKey);

        cout << "WC " << timer.getTime() << "s\n";



        //Have list be random for average case
        shuffleList(sequentialArray, sizeTwo);

        timer.startClock();

        sequentialSearch(sequentialArray, sizeTwo, searchKey);

        cout << "AC " << timer.getTime() << "s\n";



        delete[] sequentialArray;
    }


    cout << SPACER;


    //Sequential Search (1000000)
    {
        cout << "Sequential Search (1000000)" << endl;

        int* sequentialArray = new int[sizeThree];

        //Have list in order for best case
        fillList(sequentialArray, sizeThree);

        //printList(sequentialArray, sizeOne);


        timer.startClock();

        enchancedSequentialSearch(sequentialArray, sizeThree, searchKey);

        cout << "BC " << timer.getTime() << "s\n";



        //Flip list for worse case
        flipList(sequentialArray, sizeThree);

        timer.startClock();

        sequentialSearch(sequentialArray, sizeThree, searchKey);

        cout << "WC " << timer.getTime() << "s\n";



        //Have list be random for average case
        shuffleList(sequentialArray, sizeThree);

        timer.startClock();

        sequentialSearch(sequentialArray, sizeThree, searchKey);

        cout << "AC " << timer.getTime() << "s\n";



        delete[] sequentialArray;
    }


    cout << SPACER << SEPERATOR << SPACER;


    //Binary Search (100)
    {
        cout << "Binary Search (100)" << endl;

        int* binaryArray = new int[sizeOne];

        //Have list in order for best case
        fillListMidpoint(binaryArray, sizeOne, searchKey);


        timer.startClock();

        binarySearch(binaryArray, 0, sizeOne - 1, searchKey);

        cout << "BC " << timer.getTime() << "s\n";


        fillList(binaryArray, sizeOne);

        //Flip list for worse case
        flipList(binaryArray, sizeOne);

        timer.startClock();

        binarySearch(binaryArray, 0, sizeOne - 1, searchKey);

        cout << "WC " << timer.getTime() << "s\n";



        //Have list be random for average case
        shuffleList(binaryArray, sizeOne);

        timer.startClock();

        binarySearch(binaryArray, 0, sizeOne - 1, searchKey);

        cout << "AC " << timer.getTime() << "s\n";



        delete[] binaryArray;
    }


    cout << SPACER;


    //Binary Search (10000)
    {
        cout << "Binary Search (10000)" << endl;

        int* binaryArray = new int[sizeTwo];

        //Have list in order for best case
        fillListMidpoint(binaryArray, sizeOne, searchKey);

        timer.startClock();

        binarySearch(binaryArray, 0, sizeTwo - 1, searchKey);

        cout << "BC " << timer.getTime() << "s\n";

        fillList(binaryArray, sizeTwo);


        //Flip list for worse case
        flipList(binaryArray, sizeTwo);

        timer.startClock();

        binarySearch(binaryArray, 0, sizeTwo - 1, searchKey);

        cout << "WC " << timer.getTime() << "s\n";



        //Have list be random for average case
        shuffleList(binaryArray, sizeTwo);

        timer.startClock();

        binarySearch(binaryArray, 0, sizeTwo - 1, searchKey);

        cout << "AC " << timer.getTime() << "s\n";



        delete[] binaryArray;
    }


    cout << SPACER;


    //Binary Search (1000000)
    {
        cout << "Binary Search (1000000)" << endl;

        int* binaryArray = new int[sizeThree];

        //Have list in order for best case
        fillListMidpoint(binaryArray, sizeOne, searchKey);


        timer.startClock();

        binarySearch(binaryArray, 0, sizeThree - 1, searchKey);

        cout << "BC " << timer.getTime() << "s\n";

        fillList(binaryArray, sizeThree);


        //Flip list for worse case
        flipList(binaryArray, sizeThree);

        timer.startClock();

        binarySearch(binaryArray, 0, sizeThree - 1, searchKey);

        cout << "WC " << timer.getTime() << "s\n";



        //Have list be random for average case
        shuffleList(binaryArray, sizeThree);

        timer.startClock();

        binarySearch(binaryArray, 0, sizeThree - 1, searchKey);

        cout << "AC " << timer.getTime() << "s\n";



        delete[] binaryArray;
    }
    
}