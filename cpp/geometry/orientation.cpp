ll orientation(poll p1, poll p2, poll p3)
{
    ll val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0)
    {
        return 0;
    }
    return (val > 0) ? 1 : 2;
}