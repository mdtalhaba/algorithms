#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+5;
const int N = 1e5+5;

int n,e;
int dis[N];

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

vector<Edge> v;

void bellmanFord(int s)
{
    
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;

    for (int i = 1; i < n; i++)
    {
        for(auto j : v)
        {
            // int a = j.u;
            // int b = j.v;
            // int w = j.w;
            if(dis[i] != INF && dis[j.u] + j.w < dis[j.v])
            {
                dis[j.v] = dis[j.u] + j.w;
            }
        }
    }
}

int main()
{
    cin>>n>>e;
    while (e--)
    {
        int a,b,w; cin>>a>>b>>w;
        Edge ed(a,b,w);
        v.push_back(ed);
    }
    
    bellmanFord(1);
    
    for (int i = 1; i <= n; i++)
    {
        cout<<"Distense of "<<i<<" : "<<dis[i]<<endl;
    }
    

    bool cycle = false;
    for(auto j : v)
    {
        if(dis[j.u] + j.w < dis[j.v])
        {
            cycle = true;
            break;
            dis[j.v] = dis[j.u] + j.w;
        }
    }
    
    cycle == true ? cout<<"Cycle YES" : cout<<"Cycle NO";
       
    return 0;
}