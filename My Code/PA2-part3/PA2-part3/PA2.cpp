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

#include <iostream>
#include <iomanip>
#include <time.h>
#include "sortingFunctions.h"
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



    cout << SEPERATOR << endl;

    
    //Start of bubble sort
    {
        int* bubbleArray = new int[sizeOne];

        //100

        fillList(bubbleArray, sizeOne);


        //avg case
        timer.startClock();

        bubbleSort(bubbleArray, sizeOne);

        cout << "The amount of time needed to bubble sort for average case (100)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        bubbleSort(bubbleArray, sizeOne);

        cout << "The amount of time needed to bubble sort for best case (100)" << timer.getTime() << "s\n";

        //worse case
        flipList(bubbleArray, sizeOne);

        timer.startClock();

        bubbleSort(bubbleArray, sizeOne);

        cout << "The amount of time needed to bubble sort for worse case (100)" << timer.getTime() << "s\n";


        delete[] bubbleArray;

        int* bubbleArray2 = new int[sizeTwo];

        //10000
        fillList(bubbleArray2, sizeTwo);

        //avg case
        timer.startClock();

        bubbleSort(bubbleArray2, sizeTwo);

        cout << "The amount of time needed to bubble sort for average case (10000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        bubbleSort(bubbleArray2, sizeTwo);

        cout << "The amount of time needed to bubble sort for best case (10000)" << timer.getTime() << "s\n";

        //worse case
        flipList(bubbleArray2, sizeTwo);

        timer.startClock();

        bubbleSort(bubbleArray2, sizeTwo);

        cout << "The amount of time needed to bubble sort for worse case (10000)" << timer.getTime() << "s\n";


        delete[] bubbleArray2;

        long* bubbleArray3 = new long[sizeThree];

        //1000000

        fillList(bubbleArray3, sizeThree);

        //avg case
        timer.startClock();

        bubbleSort(bubbleArray3, sizeThree);

        cout << "The amount of time needed to bubble sort for average case (10000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        bubbleSort(bubbleArray3, sizeThree);

        cout << "The amount of time needed to bubble sort for best case (10000)" << timer.getTime() << "s\n";

        //worse case
        flipList(bubbleArray3, sizeThree);

        timer.startClock();

        bubbleSort(bubbleArray3, sizeThree);

        cout << "The amount of time needed to bubble sort for worse case (10000)" << timer.getTime() << "s\n";

        delete[] bubbleArray3;

    }
    //End of bubble sort


    cout << SEPERATOR << endl;


    //Start of Insertion Sort
    {
        int* insertionArray = new int[sizeOne];

        //100

        fillList(insertionArray, sizeOne);


        //avg case
        timer.startClock();

        insertionSort(insertionArray, sizeOne);

        cout << "The amount of time needed to insertion sort for average case (100)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        insertionSort(insertionArray, sizeOne);

        cout << "The amount of time needed to insertion sort for best case (100)" << timer.getTime() << "s\n";

        //worse case
        flipList(insertionArray, sizeOne);

        timer.startClock();

        insertionSort(insertionArray, sizeOne);

        cout << "The amount of time needed to insertion sort for worse case (100)" << timer.getTime() << "s\n";


        delete[] insertionArray;

        int* insertionArray2 = new int[sizeTwo];

        //10000
        fillList(insertionArray2, sizeTwo);

        //avg case
        timer.startClock();

        insertionSort(insertionArray2, sizeTwo);

        cout << "The amount of time needed to insertion sort for average case (10000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        insertionSort(insertionArray2, sizeTwo);

        cout << "The amount of time needed to insertion sort for best case (10000)" << timer.getTime() << "s\n";

        //worse case
        flipList(insertionArray2, sizeTwo);

        timer.startClock();

        insertionSort(insertionArray2, sizeTwo);

        cout << "The amount of time needed to insertion sort for worse case (10000)" << timer.getTime() << "s\n";


        delete[] insertionArray2;

        long* insertionArray3 = new long[sizeThree];

        //1000000

        fillList(insertionArray3, sizeThree);

        //avg case
        timer.startClock();

        insertionSort(insertionArray3, sizeThree);

        cout << "The amount of time needed to insertion sort for average case (1000000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        insertionSort(insertionArray3, sizeThree);

        cout << "The amount of time needed to insertion sort for best case (1000000)" << timer.getTime() << "s\n";

        //worse case
        flipList(insertionArray3, sizeThree);

        timer.startClock();

        insertionSort(insertionArray3, sizeThree);

        cout << "The amount of time needed to insertion sort for worse case (1000000)" << timer.getTime() << "s\n";

        delete[] insertionArray3;

    }
    //End of insertion sort


    cout << SEPERATOR << endl;

    
    //Start of Selection Sort
    {
        int* selectionArray = new int[sizeOne];

        //bubble sort
        //100

        fillList(selectionArray, sizeOne);


        //avg case
        timer.startClock();

        selectionSort(selectionArray, sizeOne);

        cout << "The amount of time needed to selection sort for average case (100)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        selectionSort(selectionArray, sizeOne);

        cout << "The amount of time needed to selection sort for best case (100)" << timer.getTime() << "s\n";

        //worse case
        flipList(selectionArray, sizeOne);

        timer.startClock();

        selectionSort(selectionArray, sizeOne);

        cout << "The amount of time needed to selection sort for worse case (100)" << timer.getTime() << "s\n";


        delete[] selectionArray;

        int* selectionArray2 = new int[sizeTwo];

        //10000
        fillList(selectionArray2, sizeTwo);

        //avg case
        timer.startClock();

        selectionSort(selectionArray2, sizeTwo);

        cout << "The amount of time needed to selection sort for average case (10000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        selectionSort(selectionArray2, sizeTwo);

        cout << "The amount of time needed to selection sort for best case (10000)" << timer.getTime() << "s\n";

        //worse case
        flipList(selectionArray2, sizeTwo);

        timer.startClock();

        selectionSort(selectionArray2, sizeTwo);

        cout << "The amount of time needed to selection sort for worse case (10000)" << timer.getTime() << "s\n";


        delete[] selectionArray2;

        long* selectionArray3 = new long[sizeThree];

        //1000000

        fillList(selectionArray3, sizeThree);

        //avg case
        timer.startClock();

        selectionSort(selectionArray3, sizeThree);

        cout << "The amount of time needed to selection sort for average case (1000000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        selectionSort(selectionArray3, sizeThree);

        cout << "The amount of time needed to selection sort for best case (1000000)" << timer.getTime() << "s\n";

        //worse case
        flipList(selectionArray3, sizeThree);

        timer.startClock();

        selectionSort(selectionArray3, sizeThree);

        cout << "The amount of time needed to selection sort for worse case (1000000)" << timer.getTime() << "s\n";

        delete[] selectionArray3;

    }
    //End of selection sort


    cout << SEPERATOR << endl;

    
    
    //Start of Shell Sort
    {
        int* shellArray = new int[sizeOne];

        //100
        
        fillList(shellArray, sizeOne);
        
        
        //avg case
        timer.startClock();
        
        shellSort(shellArray, sizeOne);
        
        cout << "The amount of time needed to shell sort for average case (100)" << timer.getTime() << "s\n";
        
        //best case
        timer.startClock();
        
        shellSort(shellArray, sizeOne);
        
        cout << "The amount of time needed to shell sort for best case (100)" << timer.getTime() << "s\n";
        
        //worse case
        flipList(shellArray, sizeOne);
        
        timer.startClock();
        
        shellSort(shellArray, sizeOne);
        
        cout << "The amount of time needed to shell sort for worse case (100)" << timer.getTime() << "s\n";
        
        
        delete[] shellArray;
        
        int* shellArray2 = new int[sizeTwo];
        
        //10000
        fillList(shellArray2, sizeTwo);
        
        //avg case
        timer.startClock();
        
        shellSort(shellArray2, sizeTwo);
        
        cout << "The amount of time needed to shell sort for average case (10000)" << timer.getTime() << "s\n";
        
        //best case
        timer.startClock();
        
        shellSort(shellArray2, sizeTwo);
        
        cout << "The amount of time needed to shell sort for best case (10000)" << timer.getTime() << "s\n";
        
        //worse case
        flipList(shellArray2, sizeTwo);
        
        timer.startClock();
        
        shellSort(shellArray2, sizeTwo);
        
        cout << "The amount of time needed to shell sort for worse case (10000)" << timer.getTime() << "s\n";
        
        
        delete[] shellArray2;
        
        long* shellArray3 = new long[sizeThree];
        
        //1000000
        
        fillList(shellArray3, sizeThree);
        
        //avg case
        timer.startClock();
        
        shellSort(shellArray3, sizeThree);
        
        cout << "The amount of time needed to shell sort for average case (1000000)" << timer.getTime() << "s\n";
        
        //best case
        timer.startClock();
        
        shellSort(shellArray3, sizeThree);
        
        cout << "The amount of time needed to shell sort for best case (1000000)" << timer.getTime() << "s\n";
        
        //worse case
        flipList(shellArray3, sizeThree);
        
        timer.startClock();
        
        shellSort(shellArray3, sizeThree);
        
        cout << "The amount of time needed to shell sort for worse case (1000000)" << timer.getTime() << "s\n";
        
        delete[] shellArray3;
    }
    //End of shell sort

    
    cout << SEPERATOR << endl;
    

    //Start of Quick Sort
    {
        int* quickArray = new int[sizeOne];

        //100

        fillList(quickArray, sizeOne);


        //avg case
        timer.startClock();

        quickSort(quickArray, 0, sizeOne - 1);

        cout << "The amount of time needed to quick sort for average case (100)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        quickSort(quickArray, 0, sizeOne - 1);

        cout << "The amount of time needed to quick sort for best case (100)" << timer.getTime() << "s\n";

        //worse case
        flipList(quickArray, sizeOne);

        timer.startClock();

        quickSort(quickArray, 0, sizeOne - 1);

        cout << "The amount of time needed to quick sort for worse case (100)" << timer.getTime() << "s\n";


        delete[] quickArray;

        int* quickArray2 = new int[sizeTwo];

        //10000
        fillList(quickArray2, sizeTwo);

        //avg case
        timer.startClock();

        quickSort(quickArray2, 0, sizeTwo - 1);

        cout << "The amount of time needed to quick sort for average case (10000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        quickSort(quickArray2, 0, sizeTwo - 1);

        cout << "The amount of time needed to quick sort for best case (10000)" << timer.getTime() << "s\n";

        //worse case
        flipList(quickArray2, sizeTwo);

        timer.startClock();

        quickSort(quickArray2, 0, sizeTwo - 1);

        cout << "The amount of time needed to quick sort for worse case (10000)" << timer.getTime() << "s\n";


        delete[] quickArray2;

        long* quickArray3 = new long[sizeThree];

        //1000000

        fillList(quickArray3, sizeThree);

        //avg case
        timer.startClock();

        quickSort(quickArray3, 0, sizeThree - 1);

        cout << "The amount of time needed to quick sort for average case (1000000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        quickSort(quickArray3, 0, sizeThree - 1);

        cout << "The amount of time needed to quick sort for best case (1000000)" << timer.getTime() << "s\n";

        //worse case
        flipList(quickArray3, sizeThree);

        timer.startClock();

        quickSort(quickArray3, 0, sizeThree - 1);

        cout << "The amount of time needed to quick sort for worse case (1000000)" << timer.getTime() << "s\n";

        delete[] quickArray3;
    }
    //End of quick sort


    cout << SEPERATOR << endl;


    

    //Start of Merge Sort
    {
        int* mergeArray = new int[sizeOne];

        //100

        fillList(mergeArray, sizeOne);


        //avg case
        timer.startClock();

        mergeSort(mergeArray, 0, sizeOne - 1);

        cout << "The amount of time needed to merge sort for average case (100)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        mergeSort(mergeArray, 0, sizeOne - 1);

        cout << "The amount of time needed to merge sort for best case (100)" << timer.getTime() << "s\n";

        //worse case
        flipList(mergeArray, sizeOne);

        timer.startClock();

        mergeSort(mergeArray, 0, sizeOne - 1);

        cout << "The amount of time needed to merge sort for worse case (100)" << timer.getTime() << "s\n";


        delete[] mergeArray;

        int* mergeArray2 = new int[sizeTwo];

        //10000
        fillList(mergeArray2, sizeTwo);

        //avg case
        timer.startClock();

        mergeSort(mergeArray2, 0, sizeTwo - 1);

        cout << "The amount of time needed to merge sort for average case (10000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        mergeSort(mergeArray2, 0, sizeTwo - 1);

        cout << "The amount of time needed to merge sort for best case (10000)" << timer.getTime() << "s\n";

        //worse case
        flipList(mergeArray2, sizeTwo);

        timer.startClock();

        mergeSort(mergeArray2, 0, sizeTwo - 1);

        cout << "The amount of time needed to merge sort for worse case (10000)" << timer.getTime() << "s\n";


        delete[] mergeArray2;

        long* mergeArray3 = new long[sizeThree];

        //1000000

        fillList(mergeArray3, sizeThree);

        //avg case
        timer.startClock();

        mergeSort(mergeArray3, 0, sizeThree - 1);

        cout << "The amount of time needed to merge sort for average case (1000000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        mergeSort(mergeArray3, 0, sizeThree - 1);

        cout << "The amount of time needed to merge sort for best case (1000000)" << timer.getTime() << "s\n";

        //worse case
        flipList(mergeArray3, sizeThree);

        timer.startClock();

        mergeSort(mergeArray3, 0, sizeThree - 1);

        cout << "The amount of time needed to merge sort for worse case (1000000)" << timer.getTime() << "s\n";

        delete[] mergeArray3;

    }
    //End of Merge Sort
    

    cout << SEPERATOR << endl;


    //Start of cocktail Sort
    {
    int* cocktailArray = new int[sizeOne];

    //100

    fillList(cocktailArray, sizeOne);


    //avg case
    timer.startClock();

    cocktailSort(cocktailArray, sizeOne);

    cout << "The amount of time needed to cocktail sort for average case (100)" << timer.getTime() << "s\n";

    //best case
    timer.startClock();

    cocktailSort(cocktailArray, sizeOne);

    cout << "The amount of time needed to cocktail sort for best case (100)" << timer.getTime() << "s\n";

    //worse case
    flipList(cocktailArray, sizeOne);

    timer.startClock();

    cocktailSort(cocktailArray, sizeOne);

    cout << "The amount of time needed to cocktail sort for worse case (100)" << timer.getTime() << "s\n";


    delete[] cocktailArray;

    int* cocktailArray2 = new int[sizeTwo];

    //10000
    fillList(cocktailArray2, sizeTwo);

    //avg case
    timer.startClock();

    cocktailSort(cocktailArray2, sizeTwo);

    cout << "The amount of time needed to cocktail sort for average case (10000)" << timer.getTime() << "s\n";

    //best case
    timer.startClock();

    cocktailSort(cocktailArray2, sizeTwo);

    cout << "The amount of time needed to cocktail sort for best case (10000)" << timer.getTime() << "s\n";

    //worse case
    flipList(cocktailArray2, sizeTwo);

    timer.startClock();

    cocktailSort(cocktailArray2, sizeTwo);

    cout << "The amount of time needed to cocktail sort for worse case (10000)" << timer.getTime() << "s\n";


    delete[] cocktailArray2;

    long* cocktailArray3 = new long[sizeThree];

    //1000000

    fillList(cocktailArray3, sizeThree);

    //avg case
    timer.startClock();

    cocktailSort(cocktailArray3, sizeThree);

    cout << "The amount of time needed to cocktail sort for average case (1000000)" << timer.getTime() << "s\n";

    //best case
    timer.startClock();

    cocktailSort(cocktailArray3, sizeThree);

    cout << "The amount of time needed to cocktail sort for best case (1000000)" << timer.getTime() << "s\n";

    //worse case
    flipList(cocktailArray3, sizeThree);

    timer.startClock();

    cocktailSort(cocktailArray3, sizeThree);

    cout << "The amount of time needed to cocktail sort for worse case (1000000)" << timer.getTime() << "s\n";

    delete[] cocktailArray3;

    }
    //End of cocktail sort


    cout << SEPERATOR << endl;


    
    
}

