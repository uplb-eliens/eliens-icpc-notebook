void sieve(vector<bool> &is_prime, vector<int> &prime)
{
    for (int i = 2; i < N; i++)
    {
        if (!is_prime[i])
        {
            continue;
        }
        for (int j = i * i; j < N; j += i)
        {
            is_prime[j] = 0;
        }
    }
    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
        }
    }
}