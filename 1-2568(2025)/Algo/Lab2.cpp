#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

// ธราธร เกื้อก่อบุญ 6810210140
void insertionSort(int data[], int count)
{
    int temporaryData, pos;

    for (int i = 1; i < count; i++)
    {
        temporaryData = data[i];
        pos = i;

        while (pos > 0 && data[pos - 1] > temporaryData)
        {
            data[pos] = data[pos - 1];
            pos--;
        }

        data[pos] = temporaryData;
    }
}

// ธราธร เกื้อก่อบุญ 6810210140
void shellSort(int data[], int count)
{
    int pos, temporaryData;

    for (int group = count / 2; group > 0; group = count /= 2)
    {
        for (int i = group; i < count; i++)
        {
            pos = i;
            temporaryData = data[i];

            while (pos > 0 && data[pos - group] > temporaryData)
            {
                data[pos] = data[pos - group];
                pos = pos - group;
            }

            data[pos] = temporaryData;
        }
    }
}

int par(int data[], int low, int heigh)
{
    int pivot;
    pivot = data[low];
    int i, j;
    i = low - 1;
    j = heigh + 1;

    while (i < j)
    {
        while (data[--j] > pivot)
            ;
        while (data[++i] < pivot)
            ;
        if (i < j)
        {
            swap(data[i], data[j]);
        }
    }
    return j;
}

// ธราธร เกื้อก่อบุญ 6810210140
void quickSort(int data[], int p, int r)
{
    int j;

    if (p < r)
    {
        j = par(data, p, r);
        quickSort(data, p, j);
        quickSort(data, j + 1, r);
    }
}

void getData(int data[])
{
    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        data[i] = rand() % 3;
    }
}

int main()
{

    int n[5] = {1000, 5000, 10000, 20000, 50000};

    for (int dataRounds = 0; dataRounds < 5; dataRounds++)
    {
        int run = 10;
        int dataSize = n[dataRounds];
        int *data = new int[dataSize];
        int insertionTime[10];
        int shellTime[10];
        int quickTime[10];

        getData(data);

        for (int index = 0; index < run; index++)
        {
            auto start = high_resolution_clock::now();
            insertionSort(data, dataSize);
            auto end = high_resolution_clock::now();
            insertionTime[index] =
                duration<double, micro>(end - start).count();

            start = high_resolution_clock::now();
            shellSort(data, dataSize);
            end = high_resolution_clock::now();
            shellTime[index] =
                duration<double, micro>(end - start).count();

            start = high_resolution_clock::now();
            quickSort(data, 0, dataSize - 1);
            end = high_resolution_clock::now();
            quickTime[index] =
                duration<double, micro>(end - start).count();
        }
        delete[] data;

        double sum1 = 0, sum2 = 0, sum3 = 0;

        for (int i = 0; i < run; i++)
        {
            sum1 += insertionTime[i];
            sum2 += shellTime[i];
            sum3 += quickTime[i];
        }

        double meanInsertionTime = sum1 / run;
        double meanShellTime = sum2 / run;
        double meanQuickTime = sum3 / run;

        cout << "----------------------------------------------------" << endl;
        cout << "Data size: " << dataSize << " with Insertion sort mean time taken : "
             << meanInsertionTime << " milliseconds" << endl;

        cout << "Data size: " << dataSize << " with Shell sort mean time taken : "
             << meanShellTime << " milliseconds" << endl;

        cout << "Data size: " << dataSize << " with Quick sort mean time taken : "
             << meanQuickTime << " milliseconds" << endl;
    }
    return 0;
}