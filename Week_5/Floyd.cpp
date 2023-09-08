#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int n; cin>>n;
    int dis[n+1][n+1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>dis[i][j];
        }
        
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dis[i][j] == -1) dis[i][j] = INF;
            if(i==j) dis[i][j] = 0;
        }
    }


    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
            
        }
        
    }

    int max = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dis[i][j] == INF) continue;
            if(dis[i][j] > max) max = dis[i][j];
        }
    }
    
    cout<<max;
    
       
    return 0;
}