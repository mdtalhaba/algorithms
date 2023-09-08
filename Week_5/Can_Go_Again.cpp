#include<bits/stdc++.h>
using namespace std;

const long long int INF = 1e18;

int main()
{
    int n,e; cin>>n>>e;
    long long int dis[n+1][n+1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if(i==j) dis[i][j] = 0;
        }
        
    }

    while (e--)
    {
        int a,b;
        long long int w; cin>>a>>b>>w;
        dis[a][b] = w;
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

    
    bool cycle = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==j && dis[i][j] < 0)
            {
                cycle = true;
                break;
            }
        }
    }
    
    if(cycle == true) cout<<"Negative Cycle Detected"<<endl;
    else
    {
        int s,t; cin>>s>>t;
        while (t--)
        {
            int d; cin>>d;
            if(dis[s][d]>INF-100) cout<<"Not Possible"<<endl;
            else cout<<dis[s][d]<<endl;
        }
    }
    
       
    return 0;
}