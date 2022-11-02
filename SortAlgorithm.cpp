#include <iostream>
#include <ctime>
#include <fstream>
#include <time.h>
#include "Function.h"

using namespace std;

int main()
{
    /*auto min = 0;
    auto max = 0;  
    auto step;
    auto scale;
    auto Array = new int[scale];
    int function;
    bool flag = true;
    interface();
    while (flag)
    {
        ofstream output("P:\\Repos\\SortAlgorithm\\file.txt", ios::app);
        cin >> function;
        switch (function)
        {
        case 1:
            RandomArray(Array, scale, min, max);
            break;
        }
    }*/
    auto step = 0;
    int scale;
    cout << "Enter scale massive: ";
    cin >> scale;
    int* Array = new int[scale];
    RandomArray(Array, scale, 10, 100);
    step = setArrayStep();
    //WriteInFile(Array, scale);
    //ReadFromFile(Array, scale);
    PutArray(Array, scale);
    cout << endl;
    BubbleSort(Array, scale);
    cout << "Bubble sort: ";
    PutArray(Array, scale);
    cout << endl;
    //HeapSort(Array, scale);
    //cout << "Heap sort: ";
    //PutArray(Array, scale);
}
