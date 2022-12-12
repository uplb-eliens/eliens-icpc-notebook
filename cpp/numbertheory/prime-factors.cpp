vector<int> prime_factors(int n)
{
    vector<int> res;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
    {
        res.push_back(n);
    }
    return res;
}