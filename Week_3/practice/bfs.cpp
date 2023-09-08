#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> adj[N];
vector<bool> visited(N);
vector<int> level(N);

void dfs(int s)
{
    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        visited[u] = true;
        q.pop();

        for(int v : adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
            level[v] = level[u] + 1;
        }
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
    
    dfs(0);

    for (int i = 0; i < n; i++)
    {
        cout<<"Level of "<<i<<" : "<<level[i]<<endl;
    }
    
       
    return 0;
}