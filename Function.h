#pragma once
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

long long changeCountBS = 0;
long long comparisonCountBS = 0;
long long changeCountHS = 0;
long long comparisonCountHS = 0;

void interface()
{
    cout << "1) Range array " << endl;
    cout << "2) Sorting value " << endl;
    cout << "3) Random value " << endl;
    cout << "4) Sorting array with HeapSort" << endl;
    cout << "5) Sorting array with BubbleSort" << endl;
    cout << "For exit, enter -1" << endl;
}

void RandomArray(int Arr[], int scale)
{
    srand(time(0));
    for (int i = 0; i < scale; i++)
    {
        Arr[i] = rand() % 100001;
    }
}

void SetSortValues(int* array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = i;
}

void PutArray(int Arr[], int scale)
{
    for (int i = 0; i < scale; i++)
    {
        cout << Arr[i] << " ";
    }
}

void setArraySize(int* Arr)
{   
    cout << "Left size: ";
    cin >> Arr[0];
    cout << endl;
    cout << "Right size: ";
    cin >> Arr[1];
    cout << endl;
}

int setArrayStep()
{
    int result;
    cout << "Enter size step: ";
    cin >> result;
    cout << endl;
    return result;
}

void bestHappening(int* Arr, int scale)
{
    for (int i = 0; i < scale; i++)
        Arr[i] = i;
}

void averageHappening(int* Arr, int scale)
{
    for (int i = 0; i < scale; i++)
        Arr[i] = 0 + rand() % (scale - 0 + 1);
}

void badHappening(int* Arr, int scale)
{
    for (int i = 0; i < scale; i++)
        Arr[i] = INT_MAX - i;
}

void WriteData(int size, double duration, long long swap, long long compare)
{
    ofstream output("P:\\Repos\\SortAlgorithm\\file.txt", ios::app);
    if (output.is_open())
    {
        //output << size << endl;
        //output << compare << endl;
        //output << swap << endl;
        //output << duration << endl;
        output << "Scale massive: " << size << endl;
        output << "Number operation comparison: " << compare << endl;
        output << "Number operation change: " << swap << endl;
        output << "Time: " << duration << endl;
    }
    output.close();
}

void BubbleSort(int Arr[], int scale)
{

    auto startTime = steady_clock::now();
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 0; i < scale - 1; i++) {
            if (Arr[i] > Arr[i + 1])
            {
                int temp = Arr[i];
                Arr[i] = Arr[i + 1];
                Arr[i + 1] = temp;
                flag = true;
                changeCountBS++;
            }
            comparisonCountBS++;
        }
    }
    auto endTime = steady_clock::now();
    duration <double> duration = endTime - startTime;
    WriteData(scale, duration.count(), changeCountBS, comparisonCountBS);
    changeCountBS = 0;
    comparisonCountBS = 0;
}

void Heap(int Arr[], int scale, int i)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < scale && Arr[left] > Arr[large])
    {
        large = left;
    }

    if (right < scale && Arr[right] > Arr[large])
    {
        large = right;
    }

    if (large != i)
    {
        swap(Arr[i], Arr[large]);
        Heap(Arr, scale, large);
    }
}

void HeapSort(int Arr[], int scale)
{
    auto startTime = clock();
    for (int i = scale / 2 - 1; i >= 0; i--)
    {
        comparisonCountHS++;
        Heap(Arr, scale, i);
    }
    for (int i = scale - 1; i >= 0; i--)
    {
        swap(Arr[0], Arr[i]);
        changeCountHS++;
        Heap(Arr, i, 0);
    }
    auto endTime = clock();
    double duration = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    WriteData(scale, duration, changeCountHS, comparisonCountHS);
    changeCountHS = 0;
    comparisonCountHS = 0;
}

void WriteInFile(int Arr[], int scale)
{
    ofstream input;
    //input.open("C:\\Users\\freak\\Desktop\\SortAlgorithm\\file.txt", ios::app);
    input.open("P:\\Repos\\SortAlgorithm\\file.txt");
    for (int i = 0; i < scale; i++)
    {
        input << Arr[i];
    }
    input.close();
}

void ReadFromFile(int Arr[], int scale)
{
    //ifstream output("C:\\Users\\freak\\Desktop\\SortAlgorithm\\file.txt", ios::app);
    ifstream output("P:\\Repos\\SortAlgorithm\\file.txt");
    for (int i = 0; i < scale; i++)
    {
        output >> Arr[i];
    }
    output.close();
}