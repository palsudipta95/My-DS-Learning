// // Adjacency Matrix representation of a Graph

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjMat(n, vector<int>(n, 0));

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1; // for undirected graph
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

