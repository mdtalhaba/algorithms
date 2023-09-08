#include<bits/stdc++.h>
using namespace std;

const long long int INF = 1e18;
const int N = 1e3+5;

int n,e;
long long int dis[N];

class Edge
{
    public:
    int u;
    int v;
    long long int w;
    Edge(int u, int v, long long int w)
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
            if(dis[j.u] != INF && dis[j.u] + j.w < dis[j.v])
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
        int a,b;
        long long int w; 
        cin>>a>>b>>w;

        Edge ed(a,b,w);
        v.push_back(ed);
    }
    
    int s; cin>>s;
    bellmanFord(s);

    
    

    bool cycle = false;
    for(auto j : v)
    {
        if(dis[j.u] != INF && dis[j.u] + j.w < dis[j.v])
        {
            cycle = true;
            break;
        }
    }

    if(cycle == true) cout<<"Negative Cycle Detected"<<endl;
    else
    {
        int t; cin>>t;
        while (t--)
        {
            int d; cin>>d;
            if(dis[d]==INF) cout<<"Not Possible"<<endl;
            else cout<<dis[d]<<endl;
        }
    }

    return 0;
}