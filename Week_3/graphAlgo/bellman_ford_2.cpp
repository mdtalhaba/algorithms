#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;
const int N = 1e5+5;
const int INF = 1e9+5;

vector<pr> gr[N];
int dis[N];
int n,e;

void bellmanFord(int s)
{
    for (int i = 1; i <= n; i++) dis[i] = INF;

    dis[s] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for(pr child : gr[j])
            {
                int childNode = child.first;
                int weight = child.second;

                if(dis[j] != INF && dis[childNode] > dis[j] + weight)
                {
                    dis[childNode] = dis[j] + weight;
                }
            }
        }
        
    }
    
    
}

int main()
{
    cin>>n>>e;
    while (e--)
    {
        int u,v,w; cin>>u>>v>>w;
        gr[u].push_back({v,w});
    }
    
    bellmanFord(1);

    for (int i = 1; i <= n; i++)
    {
        cout<<"Distense of "<<i<<" : "<<dis[i]<<endl;
    }
    
       
    return 0;
}