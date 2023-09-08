#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
vector<bool> visited(N);
vector<int> level(N);
vector<int> par(N);

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    par[s] = -1;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for(int child : adj[parent])
        {
            if(visited[child]) continue;
            q.push(child);
            visited[child] = true;
            level[child] = level[parent] + 1;
            par[child] = parent;
        }
    }
    
}

int main()
{
    int n,e; cin>>n>>e;
    while (e--)
    {
        int u,v;  cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(1);

    int d; cin>>d;
    vector<int> path;

    int x = d;
    while (x != -1)
    {
        path.push_back(x);
        x = par[x];
    }

    reverse(path.begin(), path.end());
    
    for(int i : path)
    {
        cout<<i<<" ";
    }
       
    return 0;
}