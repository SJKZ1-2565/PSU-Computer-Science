#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cCount,n=0;
    cin >> cCount;

    vector<int> start{cCount};
    vector<int> finish{cCount};
    for (int i = 0; i < cCount; i++)
    {
        cin >> start[i] >> finish[i];
    }
    for (int i = 0; i < cCount; i++)
    {
        for (int j = i + 1; j < cCount ; j++)
        {

            if (finish[i] < start[j])
            {
                n++;
            }
        }
    }
    cout << n;
    return 0;
}