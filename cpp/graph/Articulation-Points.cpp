void APUtil(vector<vector<int>> &adj, int u, vector<bool> &visited,
            vector<int> &disc, vector<int> &low, int &time, int parent, vector<bool> &isAP)
{
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            children++;
            APUtil(adj, v, visited, disc, low, time, u, isAP);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= disc[u])
            {
                isAP[u] = true;
            }
        }
        else if (v != parent)
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (parent == -1 && children > 1)
    {
        isAP[u] = true;
    }
}

void AP(vector<vector<int>> &adj, int n)
{
    vector<int> disc(n), low(n);
    vector<bool> visited(n), isAP(n);
    int time = 0, par = -1;
    for (int u = 0; u < n; u++)
    {
        if (!visited[u])
        {
            APUtil(adj, u, visited, disc, low, time, par, isAP);
        }
    }
    for (int u = 0; u < n; u++)
    {
        if (isAP[u])
        {
            cout << u << " ";
        }
    }
}