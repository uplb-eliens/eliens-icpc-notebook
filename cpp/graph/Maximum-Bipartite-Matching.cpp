bool bpm(int n, int m, vector<vector<bool>> &bpGraph, int u, vector<bool> &seen, vector<int> &matchR)
{
    for (int v = 0; v < m; v++)
    {
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(n, m, bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(int n, int m, vector<vector<bool>> &bpGraph)
{
    vector<int> matchR(m, -1);
    int result = 0;
    for (int u = 0; u < n; u++)
    {
        vector<bool> seen(m, false);
        if (bpm(n, m, bpGraph, u, seen, matchR))
        {
            result++;
        }
    }
    return result;
}