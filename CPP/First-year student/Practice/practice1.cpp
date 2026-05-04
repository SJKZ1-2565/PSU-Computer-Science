#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int>& list, int left, int right, int number)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (list[mid] == number)
        return mid;

    if (number < list[mid])
        return BinarySearch(list, left, mid - 1, number);
    else
        return BinarySearch(list, mid + 1, right, number);
}

int main()
{
    int n, x;
    cout << "Enter number size: ";
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    sort(list.begin(), list.end());
    cout << "Enter number to find: ";
    cin >> x;
    cout <<"Found "<< x << " at index: " << BinarySearch(list, 0, list.size() - 1, x);
    return 0;
}