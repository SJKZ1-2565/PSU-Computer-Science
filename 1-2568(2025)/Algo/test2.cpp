#include <iostream>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <vector>

using namespace std;
using namespace chrono;

// Algorithm 1: Brute Force (O(n^2)) - **ระวัง: n เยอะจะช้ามาก**
int algor1(int n, int data[]) {
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (data[i] == data[j]) c++;
        }
        if (c > n / 2) return 1;
    }
    return 0;
}

// Algorithm 2: Sort and Count (O(n log n))
int algor2(int n, int data[]) {
    if (n == 0) return 0;
    sort(data, data + n); 
    int d = data[0], c = 1;
    for (int i = 1; i < n; i++) {
        if (data[i] == d) {
            c++;
        } else {
            d = data[i];
            c = 1;
        }
        if (c > n / 2) return 1;
    }
    return 0;
}

// Algorithm 3: Boyer-Moore Voting (O(n)) - **เร็วที่สุด**
int algor3(int n, int data[]) {
    int candidate = -1, votes = 0;
    for (int i = 0; i < n; i++) {
        if (votes == 0) { candidate = data[i]; votes = 1; }
        else if (data[i] == candidate) votes++;
        else votes--;
    }
    int count = 0;
    for (int i = 0; i < n; i++) if (data[i] == candidate) count++;
    return (count > n / 2) ? 1 : 0;
}

void getData(int n, int data[]) {
    for (int i = 0; i < n; i++) data[i] = rand() % 3;
}

int main() {
    int n[] = {10000, 50000, 100000, 500000}; // ปรับ n ตามเหมาะสม
    int run = 5; // รัน 5 รอบเพื่อดูค่าเฉลี่ย

    for (int exp = 0; exp < 4; exp++) {
        int size = n[exp];
        int *data = new int[size];
        double timeAlgo2[5], timeAlgo3[5];

        cout << "Testing n = " << size << "..." << endl;

        for (int i = 0; i < run; i++) {
            getData(size, data);

            // --- Test Algorithm 2 ---
            auto start = high_resolution_clock::now();
            volatile int res2 = algor2(size, data);
            auto end = high_resolution_clock::now();
            timeAlgo2[i] = duration<double, micro>(end - start).count();

            // --- Test Algorithm 3 ---
            start = high_resolution_clock::now();
            volatile int res3 = algor3(size, data);
            end = high_resolution_clock::now();
            timeAlgo3[i] = duration<double, micro>(end - start).count();
        }

        // คำนวณสถิติ
        double m2 = 0, m3 = 0, sd2 = 0, sd3 = 0;
        for(int i=0; i<run; i++) { m2 += timeAlgo2[i]; m3 += timeAlgo3[i]; }
        m2 /= run; m3 /= run;

        for(int i=0; i<run; i++) {
            sd2 += pow(timeAlgo2[i] - m2, 2);
            sd3 += pow(timeAlgo3[i] - m3, 2);
        }
        sd2 = sqrt(sd2/run); sd3 = sqrt(sd3/run);

        cout << "Algo 2 (Sort): Mean = " << m2 << " us, SD = " << sd2 << " us" << endl;
        cout << "Algo 3 (Vote): Mean = " << m3 << " us, SD = " << sd3 << " us" << endl;
        cout << "------------------------------------" << endl;

        delete[] data;
    }
    return 0;
}