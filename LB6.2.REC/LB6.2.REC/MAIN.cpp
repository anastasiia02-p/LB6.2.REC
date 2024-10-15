#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        create(arr, SIZE, MIN, MAX, ++i);
    }
}

void Print(int* arr, const int SIZE, int i)
{
    cout << setw(4) << arr[i];
    if (i < SIZE - 1)
        Print(arr, SIZE, i + 1);
    else
        cout << endl;
}

int sum(int* arr, int SIZE, int i, int currentSum)
{
    if (i < SIZE)
    {
        if (arr[i] % 2 == 0 || !(i % 8 == 0))
            currentSum += arr[i];
        return sum(arr, SIZE, i + 1, currentSum);
    }
    return currentSum;
}

int count(int* arr, int SIZE, int i, int currentCount)
{
    if (i < SIZE)
    {
        if (arr[i] % 2 == 0 || !(i % 8 == 0))
            currentCount++;
        return count(arr, SIZE, i + 1, currentCount);
    }
    return currentCount;
}

void updateArray(int* arr, int SIZE, int i)
{
    if (i < SIZE)
    {
        if (arr[i] % 2 == 0 || !(i % 8 == 0))
            arr[i] = 0;
        updateArray(arr, SIZE, i + 1);
    }
}

void findMinMaxIndices(int* arr, int SIZE, int i, int& minIndex, int& maxIndex)
{
    if (i < SIZE)
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
        findMinMaxIndices(arr, SIZE, i + 1, minIndex, maxIndex);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    const int SIZE = 25;
    int MIN = 5;
    int MAX = 90;
    int arr[SIZE];

    create(arr, SIZE, MIN, MAX, 0);
    Print(arr, SIZE, 0);
    cout << endl;

    int minIndex = 0, maxIndex = 0;
    findMinMaxIndices(arr, SIZE, 1, minIndex, maxIndex);
    cout << "Index of min element: " << minIndex << ", value: " << arr[minIndex] << endl;
    cout << "Index of max element: " << maxIndex << ", value: " << arr[maxIndex] << endl;

    cout << "sum = " << sum(arr, SIZE, 0, 0) << endl;
    cout << "count = " << count(arr, SIZE, 0, 0) << endl;

    updateArray(arr, SIZE, 0);
    Print(arr, SIZE, 0);

    return 0;
}
