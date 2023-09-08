#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int L[n+1];
    for (int i = 0; i < n; i++) cin>>L[i];

    int m; cin>>m;
    int R[m+1];
    for (int i = 0; i < m; i++) cin>>R[i];

    L[n] = INT_MIN;
    R[m] = INT_MIN;

    int arr[n+m];

    int lp = 0, rp = 0;

    for (int i = 0; i < n+m; i++)
    {
        if(L[lp] >= R[rp])
        {
            arr[i] = L[lp];
            lp++;
        }
        else
        {
            arr[i] = R[rp];
            rp++;
        }
    }

    for (int i = 0; i < n+m; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}