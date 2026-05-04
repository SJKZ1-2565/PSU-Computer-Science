#include <iostream>
using namespace std;

void KnapsackDP(int n, int cap, int w[], int v[])
{
    int b[n+1][cap+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=cap; j++)
        {
            if(i==0 || j==0)
                b[i][j] = 0;
            else if(w[i] > j)
                b[i][j] = b[i-1][j];
            else
                b[i][j] = max(b[i-1][j], v[i] + b[i-1][j-w[i]]);
        }
    }
    //ตาราง
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=cap; j++)
        {
           cout<< b[i][j]<<"\t";
        }
        cout<<endl;
    }
    //Trace
    int max_value = b[n][cap];
    int max_cap = 0;
    cout << "\nSelected items: ";
    int i = n;
    int j = cap;
    while(i>0){
        if(max_value > b[i-1][j]){
            cout << i << " ";
            max_value -= v[i];
            max_cap += w[i];
            j -= w[i];
        }
        i--;
    }
    cout << "\nMaximum weight = " << max_cap << endl;
    cout << "Maximum value = " << b[n][cap] << endl;
}

int main()
{
    int n, cap;
    cin>>n>>cap;
    int w[n+1];
    int v[n+1];
    w[0] = 0; v[0] = 0;
    for(int i=1; i<=n; i++)
        cin>>w[i];
    for(int j=1; j<=n; j++)
        cin>>v[j];
    KnapsackDP(n, cap, w, v);

    
    return 0;
}
