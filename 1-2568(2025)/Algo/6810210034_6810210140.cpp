#include <iostream>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <ctime>

using namespace std;
using namespace chrono;

int BubbleSort(int data[], int size) // นายกิตติศักดิ์ อินศิริ 6810210034
{
    int swapped = 1; 
    int tmp; 
    while (swapped == 1) 
    {
        swapped = 0; 
        for (int i = 0; i < size - 1; i++) 
        {
            if (data[i] > data[i + 1]) 
            {
                tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
                swapped = 1;
            }
        }
    }
    return 0;
}

int SelectionSort(int data[], int size) // นายกิตติศักดิ์ อินศิริ 6810210034
{
    for (int i = 0; i < size; i++)
    {
        int tmp = data[i];
        int k = i;
        for (int j = i + 1; j < size; j++)
        {
            if (data[j] < tmp)
            {
                tmp = data[j];
                k = j;
            }
        }
        tmp = data[i];
        data[i] = data[k];
        data[k] = tmp;
    }
    return 0;
}

void InsertionSort(int data[], int count) // นายธราธร เกื้อก่อบุญ 6810210140
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

void ShellSort(int data[], int count) // นายธราธร เกื้อก่อบุญ 6810210140
{
    int pos, temporaryData;

    for (int group = count / 2; group > 0; group /= 2)
    {
        for (int i = group; i < count; i++)
        {
            pos = i;
            temporaryData = data[i];

            while (pos >= group && data[pos - group] > temporaryData)
            {
                data[pos] = data[pos - group];
                pos = pos - group;
            }

            data[pos] = temporaryData;
        }
    }
}

int par(int data[], int low, int heigh) // นายธราธร เกื้อก่อบุญ 6810210140
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

void QuickSort(int data[], int p, int r) // นายธราธร เกื้อก่อบุญ 6810210140
{
    int j;
    if (p < r)
    {
        j = par(data, p, r);
        QuickSort(data, p, j);
        QuickSort(data, j + 1, r);
    }
}

void Merge(int data[], int p, int q, int r) // นายกิตติศักดิ์ อินศิริ 6810210034
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++)
        L[i] = data[p + i];

    for (int j = 0; j < n2; j++)
        R[j] = data[q + 1 + j];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int x = 0, y = 0;

    for (int k = p; k <= r; k++)
    {
        if (L[x] <= R[y])
        {
            data[k] = L[x];
            x++;
        }
        else
        {
            data[k] = R[y];
            y++;
        }
    }
}

int MergeSort(int data[], int p, int r) // นายกิตติศักดิ์ อินศิริ 6810210034
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        MergeSort(data, p, q);
        MergeSort(data, q + 1, r);
        Merge(data, p, q, r);
    }
    return 0;
}

void get_data(int n, int data[])
{
    for (int i = 0; i < n; i++)
        data[i] = rand() % 100;
}

int main()
{
    int n[5] = {1000, 5000, 10000, 20000, 50000};
    int run = 10;

    for (int exp = 0; exp < 5; exp++)
    {
        int size = n[exp];
        int *data = new int[size];

        double time1[10], time2[10], time3[10], time4[10], time5[10], time6[10];

        for (int index = 0; index < run; index++)
        {
            // random data
            get_data(size, data);

            auto start = high_resolution_clock::now();
            BubbleSort(data, size);
            auto end = high_resolution_clock::now();
            time1[index] =
                duration<double, micro>(end - start).count();

            start = high_resolution_clock::now();
            SelectionSort(data, size);
            end = high_resolution_clock::now();
            time2[index] =
                duration<double, micro>(end - start).count();

            start = high_resolution_clock::now();
            InsertionSort(data, size);
            end = high_resolution_clock::now();
            time3[index] =
                duration<double, micro>(end - start).count();

            start = high_resolution_clock::now();
            ShellSort(data, size);
            end = high_resolution_clock::now();
            time4[index] =
                duration<double, micro>(end - start).count();

            start = high_resolution_clock::now();
            MergeSort(data, 0, size - 1);
            end = high_resolution_clock::now();
            time5[index] =
                duration<double, micro>(end - start).count();

            start = high_resolution_clock::now();
            QuickSort(data, 0, size - 1);
            end = high_resolution_clock::now();
            time6[index] =
                duration<double, micro>(end - start).count();

            cout << (1 + index) * 10 << "%" << endl;
        }
        delete[] data;

        // ===== ค่าเฉลี่ย =====
        double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0;
        for (int i = 0; i < run; i++)
        {
            sum1 += time1[i];
            sum2 += time2[i];
            sum3 += time3[i];
            sum4 += time4[i];
            sum5 += time5[i];
            sum6 += time6[i];
        }

        double mean1 = sum1 / run;
        double mean2 = sum2 / run;
        double mean3 = sum3 / run;
        double mean4 = sum4 / run;
        double mean5 = sum5 / run;
        double mean6 = sum6 / run;

        cout << "-----------------------------------------------------" << endl;
        cout << "n = " << size << endl;

        cout << "Bubble Avg= " << mean1 << endl;
        for (int i = 0; i < run; i++)
        {
            cout << time1[i] << ", ";
        }
        cout << endl;

        cout << "Selection Avg= " << mean2 << endl;
        for (int i = 0; i < run; i++)
        {
            cout << time2[i] << ", ";
        }
        cout << endl;

        cout << "Insert Avg= " << mean3 << endl;
        for (int i = 0; i < run; i++)
        {
            cout << time3[i] << ", ";
        }
        cout << endl;

        cout << "Shell Avg= " << mean4 << endl;
        for (int i = 0; i < run; i++)
        {
            cout << time4[i] << ", ";
        }
        cout << endl;

        cout << "Merge Avg= " << mean5 << endl;
        for (int i = 0; i < run; i++)
        {
            cout << time5[i] << ", ";
        }
        cout << endl;

        cout << "Quick Avg= " << mean6 << endl;
        for (int i = 0; i < run; i++)
        {
            cout << time6[i] << ", ";
        }
        cout << endl;


    }

    return 0;
} 