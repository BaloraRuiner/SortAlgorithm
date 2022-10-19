#include <iostream>
#include <ctime>

using namespace std;

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

void BubbleSort(int Arr[], int scale)
{
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
            }
        }
    }
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
        //Heap(Arr, scale, large);
    }
}

void HeapSort(int Arr[], int scale)
{
    for (int i = scale / 2 - 1; i >= 0; i--)
    {
        Heap(Arr, scale, i);
    }
    for (int i = scale - 1; i >= 0; i--)
    {
        swap(Arr[0], Arr[i]);
        Heap(Arr, i, 0);
    }
}

int main()
{
    int scale;
    cout << "Enter scale massive: ";
    cin >> scale;
    int* Array = new int[scale];
    RandomArray(Array, scale, 1, 10);
    PutArray(Array, scale);
    cout << endl;
    BubbleSort(Array, scale);
    cout << "Bubble sort: ";
    PutArray(Array, scale);
    cout << endl;
    HeapSort(Array, scale);
    cout << "Heap sort: ";
    PutArray(Array, scale);
}
