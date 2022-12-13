void bridge_util(vector<vector<int>> &adj, int u, vector<bool> &visited,
                 vector<int> &disc, vector<int> &low, vector<int> &parent)
{
    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            bridge_util(adj, v, visited, disc, low, parent);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
            {
                cout << u << " " << v << endl;
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void bridge(vector<vector<int>> &adj, int n)
{
    vector<bool> visited(n, false);
    vector<int> disc(n), low(n), parent(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bridge_util(adj, i, visited, disc, low, parent);
        }
    }
}