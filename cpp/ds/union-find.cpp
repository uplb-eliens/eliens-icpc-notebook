ll find(struct subset subsets[], ll i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(struct subset subsets[], ll x, ll y)
{
    ll x_root = find(subsets, x);
    ll y_root = find(subsets, y);
    if (subsets[x_root].rank < subsets[y_root].rank)
    {
        subsets[x_root].parent = y_root;
    }
    else if (subsets[x_root].rank > subsets[y_root].rank)
    {
        subsets[y_root].parent = x_root;
    }
    else
    {
        subsets[y_root].parent = x_root;
        subsets[x_root].rank++;
    }
}