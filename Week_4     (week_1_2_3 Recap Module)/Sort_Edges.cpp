#include<bits/stdc++.h>
#define pr pair<int,int>
using namespace std;
int main()
{
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    int q; cin>>q;
    while (q--)
    {
        int u,v; cin>>u>>v;
        pq.push({u,v});
    }
    
    while (!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    
       
    return 0;
}