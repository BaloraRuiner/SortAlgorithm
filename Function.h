#pragma once
#include <fstream>

using namespace std;

long long changeCountBS = 0;
long long comparisonCountBS = 0;

void interface()
{
    cout << "1) Заполение массива случайными числами" << endl;
    cout << "2) Чтение набора данных с файла" << endl;
    cout << "3) Запись набора данный в файл" << endl;
    cout << "4) Сортирование массива обменной сортировкой(пузырьковая)" << endl;
    cout << "5) Сортирование массива сортировки перемешиванием" << endl;
    cout << "For exit, enter -1" << endl;
}

void RandomArray(int Arr[], int scale, int minBorder, int maxBorder)
{
    srand(time(0));
    for (int i = 0; i < scale; i++)
    {
        Arr[i] = minBorder + (rand() % (maxBorder - minBorder));
    }
}

void PutArray(int Arr[], int scale)
{
    for (int i = 0; i < scale; i++)
    {
        cout << Arr[i] << " ";
    }
}

int setArrayStep()
{
    int result;
    cout << "Enter size step: ";
    cin >> result;
    cout << endl;
    return result;
}

void writeDataBS(int scale, const clock_t& endTime, const clock_t& startTime)
{
    ofstream output("P:\\Repos\\SortAlgorithm\\file.txt", ios::app);
    if (output.is_open())
    {
        output << "Scale massive: " << scale << endl;
        output << "Number operation comparison: " << comparisonCountBS << endl;
        output << "Number operation change: " << changeCountBS << endl;
        output << "Time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;
    }
}

void BubbleSort(int Arr[], int scale)
{
    auto startTime = clock();
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
    auto endTime = clock();
    writeDataBS(scale, startTime, endTime);
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
        Heap(Arr, scale, i);
    }
    for (int i = scale - 1; i >= 0; i--)
    {
        swap(Arr[0], Arr[i]);
        Heap(Arr, i, 0);
    }
    auto endTime = clock();
    writeDataBS(scale, endTime, startTime);
}

void WriteInFile(int Arr[], int scale)
{
    ofstream input;
    input.open("P:\\Repos\\SortAlgorithm\\file.txt");
    for (int i = 0; i < scale; i++)
    {
        input << Arr[i];
    }
    input.close();
}

void ReadFromFile(int Arr[], int scale)
{
    ifstream output("P:\\Repos\\SortAlgorithm\\file.txt");
    for (int i = 0; i < scale; i++)
    {
        output >> Arr[i];
    }
    output.close();
}