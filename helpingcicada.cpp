#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1e6 + 6
#define MOD 1000000007LL

using namespace std;

vector<lli> fac;
vector<lli> ifac;
vector<lli> smallestprimedivisor(MAX + 1);
vector<lli> derangenums(MAX + 1);
vector<lli> primes;

vector<lli> getPrimeFactorization(lli x)
{
    // logn time, uses sieve
    vector<lli> ret;
    while (x > 1)
    {
        ret.push_back(smallestprimedivisor[x]);
        x = x / smallestprimedivisor[x];
    }
    return ret;
}

vector<lli> getPrimeFactorization2(lli n)
{

    // sqrt(n),doesn't use sieve
    vector<lli> ret;
    lli x = n;
    while (x % 2 == 0)
    {
        ret.push_back(2);
        x = x / 2;
    }

    for (lli i = 3; i * i <= x; i += 2)
    {

        while (x % i == 0)
        {
            ret.push_back(i);
            x = x / i;
        }
    }
    if (x > 2)
        ret.push_back(x);

    return ret;
}

string bigIntMultiply(string &s, lli b)
{
    string ans = "";
    int carry = 0;

    // multiplying reversely

    for (int i = 0; i < s.size(); i++)
    {
        carry = (s[i] - '0') * b + carry;
        ans += carry % 10 + '0';
        carry /= 10;
    }

    while (carry > 0)
    {
        ans += carry % 10 + '0';
        carry /= 10;
    }

    // ans is reverse
    return ans;
}

void sieve()
{

    for (lli i = 0; i <= MAX; i++)
        smallestprimedivisor[i] = i;

    for (lli i = 2; i * i <= MAX; i++)
    {
        if (smallestprimedivisor[i] == i)
        {

            for (lli j = i * i; j <= MAX; j += i)
            {
                if (smallestprimedivisor[j] == j)
                    smallestprimedivisor[j] = i;
            }
        }
    }

    for (lli i = 2; i <= MAX; i++)
    {
        if (smallestprimedivisor[i] == i)
            primes.push_back(i);
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

lli gcd(lli a, lli b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

lli gcdExtended(lli a, lli b, lli *x, lli *y)
{
    // ax+by=gcd(a,b);

    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    lli x1, y1;

    lli g = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return g;
}

lli modInverse(lli num, lli M)
{
    lli x, y;
    lli g = gcdExtended(num, M, &x, &y);

    if (g != 1)
    {
        // no inverse exists
        return -INT_MAX;
    }
    return (x % M + M) % M;
}

lli InverseModuloPrime(lli num, lli M)
{
    lli g = gcd(num, M);

    if (g != 1)
    {
        // no inverse exists
        return -INT_MAX;
    }

    return binExp(num, M - 2LL);
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

    for (lli j = 3; j <= MAX; j++)
    {
        derangenums[j] = ((j - 1) * (derangenums[j - 1] + derangenums[j - 2]) % MOD) % MOD;
    }
}

vector<lli> segmentedSieve(lli low, lli high)
{
    // use sieve for first sqrt(n) numbers first

    vector<lli> primesinsegment;
    vector<lli> mark(high - low + 2, 1); // space optimization

    for (lli i = 0; i < primes.size(); i++)
    {
        if (primes[i] > high)
            break;

        lli lowest = ((low + primes[i] - 1) / primes[i]) * primes[i];

        for (lli j = lowest; j <= high; j += primes[i])
        {
            if (primes[i] != j)
                mark[j - low] = 0;
        }
    }

    for (lli j = max(low, 2LL); j <= high; j++)
    {
        if (mark[j - low] == 1)
            primesinsegment.push_back(j);
    }

    return primesinsegment;
}

int main()
{
    // sieve();

    lli t;
    cin >> t;
    lli ff = t;

    while (t--)
    {
        lli n, m;
        cin >> n >> m;

        vector<lli> nums(m);

        for (lli j = 0; j < m; j++)
        {
            cin >> nums[j];
        }
        lli ans = 0;

        for (lli mask = 1; mask < (1 << m); mask++)
        {
            //cout<<mask<<"\n";
            lli lcm = 1;
            for (lli j = 0; j < m; j++)
            {
                if ((mask & (1 << j)) !=0 )
                {
                    lcm = (lcm * nums[j]) / __gcd(lcm, nums[j]);
                   
                }
            }

            lli div = n / lcm;

            if ((__builtin_popcount(mask) % 2) == 0)
            {
                ans -= div;
            }
            else
                ans += div;

               
        }

          cout << "Case " << ff - t << ": ";


        cout << n-ans << "\n";
    }
}