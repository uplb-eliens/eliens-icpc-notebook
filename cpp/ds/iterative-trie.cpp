int trie[MAX_N * 30][3], nxt;
void trie_init(int n)
{
    int nn = (n + 2) * 30;
    for (int i = 0; i < nn; i++)
        trie[i][0] = trie[i][1] = trie[i][2] = -1;
    nxt = 1;
}
void trie_insert(int v, int x)
{
    int cur = 0;
    for (int i = 29; i >= 0; i--)
    {
        int bit = v >> i & 1;
        if (trie[cur][bit] == -1)
            trie[cur][bit] = nxt++;
        cur = trie[cur][bit];
        trie[cur][2] = max(trie[cur][2], x);
    }
}

int trie_getmax(int v, int m)
{
    int cur = 0, mx = -1;
    for (int i = 29; i >= 0; i--)
    {
        int bit = v >> i & 1;
        if (m >> i & 1)
            cur = trie[cur][!bit];
        else
        {
            int lt = trie[cur][!bit];
            if (lt != -1)
                mx = max(mx, trie[lt][2]);
            cur = trie[cur][bit];
        }
        if (cur == -1)
            break;
    }
    if (cur != -1)
        mx = max(mx, trie[cur][2]);
    return mx;
}
