bool is_cyclic_util(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &rec)
{
    vis[u] = true;
    rec[u] = true;
    for (auto v : adj[u])
    {
        if (!vis[v] && is_cyclic_util(v, adj, vis, rec))
        {
            return true;
        }
        else if (rec[v])
        {
            return true;
        }
    }
    rec[u] = false;
    return false;
}