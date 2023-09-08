#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<pair<int,int>> adj[N];
int visited[N];
int dis[N];

void dijkstra(int s)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    dis[s] = 0;
    while (!pq.empty())
    {
        pair<int,int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        int parentCost = parent.first;
        
        if(visited[parentNode]) continue;
        visited[parentNode] = true;

        for(pair<int,int> child : adj[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode],childNode});
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