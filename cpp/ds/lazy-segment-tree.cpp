LL lconstruct(LL *a, LL *st, LL ss, LL se, LL si)
{
    if (ss == se)
    {
        st[si] = a[ss];
        return st[si];
    }
    LL mid = ss + (se - ss) / 2;
    st[si] = (lconstruct(a, st, ss, mid, si * 2 + 1) + lconstruct(a, st, mid + 1, se, si * 2 + 2));
    return st[si];
}
LL lgs(LL *st, LL l, LL r, LL ss, LL se, LL si, LL *lazy)
{
    if (lazy[si])
        // same as update
        if (ss > r || se < l || ss > se)
            return 0;
    if (l <= ss && r >= se)
    {
        return st[si];
    }
    LL mid = ss + (se - ss) / 2;
    return (lgs(st, l, r, ss, mid, si * 2 + 1, lazy) + lgs(st, l, r, mid + 1, se, si * 2 + 2, lazy));
}
void lupdate(LL *st, LL ss, LL se, LL ql, LL qr, LL diff, LL si, LL *lazy)
{
    if (lazy[si])
    {
        st[si] = (st[si] + (se - ss + 1) * lazy[si]);
        if (ss != se)
        {
            lazy[si * 2 + 1] = (lazy[si * 2 + 1] + lazy[si]);
            lazy[si * 2 + 2] = (lazy[si * 2 + 2] + lazy[si]);
        }
        lazy[si] = 0;
    }
    if (ss > se || qr < ss || ql > se)
        return;
    if (ss >= ql && se <= qr)
    {
        st[si] = (st[si] + (se - ss + 1) * diff);
        if (ss != se)
        {
            lazy[si * 2 + 1] = (lazy[si * 2 + 1] + diff);
            lazy[si * 2 + 2] = (lazy[si * 2 + 2] + diff);
        }
        return;
    }
    if (ss != se)
    {
        LL mid = ss + (se - ss) / 2;
        lupdate(st, ss, mid, ql, qr, diff, si * 2 + 1, lazy);
        lupdate(st, mid + 1, se, ql, qr, diff, si * 2 + 2, lazy);
    }
    st[si] = (st[2 * si + 1] + st[2 * si + 2]);
}