#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<int> adj[N];
vector<int> level(N);
vector<bool> visited(N);

void bfs(int s)
{
    queue<int> q;
    visited[s] = true;
    level[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for(int child : adj[parent])
        {
            if(visited[child]) continue;
            visited[child] = true;
            q.push(child);
            level[child] = level[parent] + 1;
        }
    }
    
}

int main()
{
    int n,e; cin>>n>>e;
    while (e--)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout<<"Level of "<<i<<" : "<<level[i]<<endl;
    }
    
       
    return 0;
}