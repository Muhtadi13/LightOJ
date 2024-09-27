#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 1000000007

using namespace std;

vector<lli> fac;
vector<lli> ifac;
vector<lli> smallestprimedivisor(MAX + 1);
vector<lli> derangenums(MAX);

void sieve()
{

    for (lli i = 0; i <= MAX; i++)
        smallestprimedivisor[i] = i;

    for (lli i = 2; i * i <= MAX; i++)
    {
        if (smallestprimedivisor[i] == i)
        {
            for (lli j = i * 2; j <= MAX; j += i)
            {
                if (smallestprimedivisor[j] == j)
                    smallestprimedivisor[j] = i;
            }
        }
    }
}

lli binExp(lli base, lli exp)
{
    base %= MOD;
    lli res = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res = (lli)((long long)res * base % MOD);
        }
        base = (lli)((long long)base * base % MOD);
        exp >>= 1;
    }
    return res;
}

void precomputeFactorial(lli n)
{
    fac.resize(n + 1);
    fac[0] = fac[1] = 1;
    for (lli i = 2; i <= n; i++)
    {
        fac[i] = (lli)((long long)i * fac[i - 1] % MOD);
    }

    ifac.resize(n + 1);
    for (lli i = 0; i < fac.size(); i++)
    {
        ifac[i] = binExp(fac[i], MOD - 2);
    }
    return;
}

lli nCr(lli n, lli r)
{
    if ((n < 0) || (r < 0) || (r > n))
    {
        return 0;
    }
    return (lli)((long long)fac[n] * ifac[r] % MOD * ifac[n - r] % MOD);
}

void derangement()
{
    derangenums[0] = 1;
    derangenums[1] = 0;
    derangenums[2] = 1;

    for (lli j = 3; j < MAX; j++)
    {
        derangenums[j] = ((j - 1) * (derangenums[j - 1] + derangenums[j - 2]) % MOD) % MOD;
    }
}

int main()
{
    lli t = 1;
    cin >> t;
    lli ff = t;

    precomputeFactorial(MAX);
    derangement();

    while (t--)
    {
        lli n, m, k;

        cin >> n >> m >> k;

        lli ans = nCr(m, k);

        lli calc[n + 1];

        calc[1] = ((n - m) * (fac[n - m])) % MOD;

        calc[0] = (fac[n - m]);

        for (lli i = 2; i <= m - k; i++)
        {
            calc[i] = (((i - 1) * (calc[i - 1] + calc[i - 2]) % MOD) % MOD + ((n - m) * (calc[i - 1])) % MOD) % MOD;
        }

        // cout << ans << "\n";

       

        cout << (calc[m - k] * ans) % MOD << '\n';

        // cout<<derangenums[10]<<"\n";

        // cout<<ans<<'\n';
    }
}