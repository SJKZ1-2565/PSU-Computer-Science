#include <iostream>
#include <algorithm>
#include <chrono>
#include <math.h>

using namespace std;
using namespace chrono;

//algor 3.1
int algor1(int n, int data[])
{
    for(int i=0; i<n; i++)
    {
        int c = 0;
        for(int j=0; j<n; j++){
            if(data[i] == data[j])
                c++;
        }
        if(c > n/2)
            return 1;
    }
    return 0;
}


//algor 3.2
int algor2(int n, int data[])
{
    if (n==1)
        return 1;
    sort(data, data + n);
    int d = data[0], c=1;
    for(int i=1; i<n; i++)
    {
        if(d == data[i])
            c++;
        else
        {
            d = data[i];
            c = 1;
        }
        if(c > n/2)
            return 1;
    }

    return 0;
}

void getData(int n, int data[])
{
    for (int i = 0; i < n; i++)
    {
        data[i] = rand() % 3;
    }
}
int main()
{
    int n[4] = {50000, 100000, 200000, 500000};
    int run = 10;
    int timeLoop[10];
    int timeFormula[10];

    for (int exp = 0; exp < 4; exp++)
    {
        int size = n[exp];
        int* data = new int[size];
        for (int i = 0; i < run; i++) {
            getData(size,data);
            auto start = high_resolution_clock::now();
            volatile long long a = algor1(size, data);
            auto end = high_resolution_clock::now();
            timeLoop[i] =
                duration<double, micro>(end - start).count();

            start = high_resolution_clock::now();
            volatile long long b = algor2(size, data);
            end = high_resolution_clock::now();
            timeFormula[i] =
                duration<double, micro>(end - start).count();
            cout << size << " Finished " << (i+1)*10 << "%" << endl; 
        }
        delete[] data;

        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < run; i++) {
            sum1 += timeLoop[i];
            sum2 += timeFormula[i];
        }

        double mean1 = sum1 / run;
        double mean2 = sum2 / run;

        double sd1 = 0, sd2 = 0;
        for (int i = 0; i < run; i++) {
            sd1 += (timeLoop[i] - mean1) *
                       (timeLoop[i] - mean1);
            sd2 += (timeFormula[i] - mean2) *
                          (timeFormula[i] - mean2);
        }

        sd1 = sqrt(sd1 / run);
        sd2 = sqrt(sd2 / run);

        cout << "n = " << size << endl;
        cout << "3.1    : mean = " << mean1
             << " us, sd = " << sd1 << " us" << endl;
        cout << "3.2 : mean = " << mean2
             << " us, sd = " << sd2 << " us" << endl;
        cout << "----------------------------" << endl;

    }
    return 0;
}