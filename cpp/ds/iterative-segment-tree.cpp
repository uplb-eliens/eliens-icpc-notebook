void build()
{
    for (LL i = n - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];
}
void modify(LL p, LL value)
{ // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}
LL query(LL l, LL r)
{ // sum on LLerval [l, r)
    LL res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
}
