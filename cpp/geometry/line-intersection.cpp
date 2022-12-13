bool on_segment(poll p, poll q, poll r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.q, r.y))
    {
        return true;
    }
    return false;
}
bool do_intersect(poll p1, poll q1, poll p2, poll q2)
{
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
    {
        return true;
    }
    if (o1 == 0 && on_segment(p1, p2, q1))
    {
        return true;
    }
    else if (o2 == 0 && on_segment(p1, q2, q1))
    {
        return true;
    }
    else if (o3 == 0 && on_segment(p2, p1, q2))
    {
        return true;
    }
    else if (o4 == 0 && on_segment(p2, q1, q2))
    {
        return true;
    }
    return false;
}