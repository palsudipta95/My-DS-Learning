#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int,int>> adj[n+1];
    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }
    
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pair<int,int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();
        int u = p.second;
        int c = -p.first;
        for(int i = 0; i < adj[u].size(); i++)
        {
            pair<int, int> pv = adj[u][i];
            int v = pv.first;
            int vc = pv.second;
            int d = c + vc;
            if(d < dist[v])
            {
                dist[v] = d;
                pq.push({-d, v});
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << "Distance from 1 to " << i << " : " << dist[i] << "\n";
    }

    return 0;
}