#include <iostream>
#include <iomanip>
//#include "sortingFunctions.h"
//#include "timerSystem.h"

using namespace std;

cocktailSort();
cocktailSort();
cocktailSort();
mergeSort();
int main()
{
    //Start of Shell Sort
    {
        int* mergeArray = new int[sizeOne];

        //100

        fillList(mergeArray, sizeOne);


        //avg case
        timer.startClock();

        mergeSort(mergeArray, 0, sizeOne - 1);

        cout << "The amount of time needed to shell sort for average case (100)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        mergeSort(mergeArray, 0, sizeOne - 1);

        cout << "The amount of time needed to shell sort for best case (100)" << timer.getTime() << "s\n";

        //worse case
        flipList(mergeArray, sizeOne);

        timer.startClock();

        mergeSort(mergeArray, 0, sizeOne - 1);

        cout << "The amount of time needed to shell sort for worse case (100)" << timer.getTime() << "s\n";


        delete[] mergeArray;

        int* mergeArray2 = new int[sizeTwo];

        //10000
        fillList(mergeArray2, sizeTwo);

        //avg case
        timer.startClock();

        mergeSort(mergeArray2, 0, sizeTwo - 1);

        cout << "The amount of time needed to shell sort for average case (10000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        mergeSort(mergeArray2, 0, sizeTwo - 1);

        cout << "The amount of time needed to shell sort for best case (10000)" << timer.getTime() << "s\n";

        //worse case
        flipList(mergeArray2, sizeTwo);

        timer.startClock();

        mergeSort(mergeArray2, 0, sizeTwo - 1);

        cout << "The amount of time needed to shell sort for worse case (10000)" << timer.getTime() << "s\n";


        delete[] mergeArray2;

        long* mergeArray3 = new long[sizeThree];

        //1000000

        fillList(mergeArray3, 0, sizeThree - 1);

        //avg case
        timer.startClock();

        mergeSort(mergeArray3, 0, sizeThree - 1);

        cout << "The amount of time needed to shell sort for average case (1000000)" << timer.getTime() << "s\n";

        //best case
        timer.startClock();

        mergeSort(mergeArray3, 0, sizeThree - 1);

        cout << "The amount of time needed to shell sort for best case (1000000)" << timer.getTime() << "s\n";

        //worse case
        flipList(mergeArray3, sizeThree);

        timer.startClock();

        mergeSort(mergeArray3, 0, sizeThree - 1);

        cout << "The amount of time needed to shell sort for worse case (1000000)" << timer.getTime() << "s\n";

        delete[] mergeArray3;

    }

}
