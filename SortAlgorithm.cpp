#include <iostream>
#include <ctime>
#include <fstream>
#include <time.h>
#include "Function.h"

using namespace std;

int main()
{
    ofstream ofs;
    ofs.open("file.txt", ofstream::out | ofstream::trunc);
    ofs.close();
    auto min = 0;
    auto max = 0;  
    auto step = 0;
    auto currentScale = 0;
    auto Array = new int[min];
    int function;
    int Arr[2];
    bool sorting = false;
    bool flag = true;
    interface();
    while (flag)
    {
        ofstream output("P:\\Repos\\SortAlgorithm\\file.txt", ios::app);
        cin >> function;
        switch (function)
        {
        case 1:
            setArraySize(Arr);
            min = Arr[0];
            max = Arr[1];
            step = setArrayStep();
            break;
        case 2:
            if (output.is_open())
            {
                output << "New" << endl;
                output << string(32, '-') << endl;
            }
            for (int i = min; i <= max; i+=step)
            {
                Array = new int[i];
                if (!sorting)
                    RandomArray(Array, i);
                HeapSort(Array, i);
                currentScale = i;
            }
            break;
        case 3:
            if (output.is_open())
            {
                output << "New" << endl;
                output << string (32, '-') << endl;
            }
            for (int i = min; i <= max; i+=step)
            {
                Array = new int[i];
                if (!sorting)
                    RandomArray(Array, i);
                BubbleSort(Array, i);
                currentScale = i;
            }
            break;
        case -1:
            flag = false;
            break;
        }
        output.close();
    }
}
