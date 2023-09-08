#include<bits/stdc++.h>
using namespace std;

const int INF = 1e7;

class Edge
{
    public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n,e; cin>>n>>e;
    vector<Edge> v;
    while (e--)
    {
        int a,b,w; cin>>a>>b>>w;
        Edge ed(a,b,w);
        v.push_back(ed);
    }

    int dis[n+1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[1] = 0;
    
    for (int i = 1; i < n; i++)
    {
        for(auto j : v)
        {
            if(dis[j.u] + j.w < dis[j.v])
            {
                dis[j.v] = dis[j.u] + j.w;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(dis[i]==INF) cout<<30000<<" ";
        else cout<<dis[i]<<" ";
    }
    
       
    return 0;
}