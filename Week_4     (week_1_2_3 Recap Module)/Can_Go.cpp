#include<bits/stdc++.h>
#define pr pair<long long int, long long int>
using namespace std;

const int N = 1e5+5;

vector<pr> adj[N];
bool visited[N];
long long int dis[N];

void dijkstra(int s)
{
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({0,s});
    dis[s] = 0;

    while (!pq.empty())
    {
        pr parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        int parentCost = parent.first;
        
        if(visited[parentNode]) continue;
            visited[parentNode] = true;

        for(pr child : adj[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(dis[parentNode] + childCost < dis[childNode])
            {
                dis[childNode] = dis[parentNode] + childCost;
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
    }

    for (int i = 0; i <= n; i++)
    {
        dis[i] = 1e13;
    }
    
    int src; cin>>src;
    dijkstra(src);

    int q; cin>>q;
    while (q--)
    {
        int destination, cost;
        cin>>destination>>cost;
        if(dis[destination] <= cost) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
       
    return 0;
}