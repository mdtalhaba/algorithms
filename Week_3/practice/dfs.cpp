#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> adj[N];
vector<bool> visited(N);

void bfs(int s)
{
    visited[s] = true;
    for(int v : adj[s])
    {
        if(visited[v]) continue;
        bfs(v);
    }
}

int main()
{
    int n,m; cin>>n>>m;

    for (int i = 0; i < m; i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(0);
    
    for (int i = 0; i < n; i++)
    {
        cout<<"List of "<<i<<" : ";
        for(int j : adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
       
    return 0;
}