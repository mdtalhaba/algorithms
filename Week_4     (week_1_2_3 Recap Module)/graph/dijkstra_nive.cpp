#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<pair<int,int>> adj[N];
int dis[N];

void dijkstra(int s)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for(pair<int,int> child : adj[parent])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(dis[parent] + childCost < dis[childNode])
            {
                dis[childNode] = dis[parent] + childCost;
                q.push(childNode);
            }
        }
    }
    
}

int main()
{
    int n,e; cin>>n>>e;
    while (e--)
    {
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for (int i = 0; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    
    
    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout<<"Distense of "<<i<<" : "<<dis[i]<<endl;
    }
    
       
    return 0;
}