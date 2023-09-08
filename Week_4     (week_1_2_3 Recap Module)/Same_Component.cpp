#include<bits/stdc++.h>
#define pr pair<int,int>
using namespace std;

const int N = 1e3+5;

int n,m;
char ar[N][N];
int visited[N][N];
vector<pr> path = {{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(int ci, int cj)
{
    return (ci>=0 && ci<n && cj>=0 && cj<m && ar[ci][cj]=='.');
}

void dfs(int pi, int pj)
{
    visited[pi][pj] = true;
    for (int i = 0; i < 4; i++)
    {
        pr p = path[i];
        int ci = pi+p.first;
        int cj = pj+p.second;
        if(isValid(ci,cj) && !visited[ci][cj])
        {
            dfs(ci,cj);
        }
    }
    
}

int main()
{
    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>ar[i][j];
        }
        
    }

    int si,sj; cin>>si>>sj;
    int di,dj; cin>>di>>dj;

    dfs(si,sj);

    if(visited[di][dj]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}