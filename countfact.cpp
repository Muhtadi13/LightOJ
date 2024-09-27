#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 2025LL
#define MOD 998244353LL
#define MAXNUM 1000006

using namespace std;

vector<lli> fac;
vector<lli> ifac;
vector<lli> smallestprimedivisor(MAXNUM);
 lli n;

void sieve()
{

    for (lli i = 0; i <=MAXNUM ; i++)
        smallestprimedivisor[i] = i;

    for (lli i = 2; i * i <= MAXNUM; i++)
    {
        if (smallestprimedivisor[i] == i)
        {
            for (lli j = i * 2; j <= MAXNUM; j += i)
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

lli dp[2*MAX+1][MAX+1];

lli getways(lli ind, lli bases, vector<pair<lli, lli>> &primes)
{
    if (ind == 0 && bases != 0)
        return dp[ind][bases]=0;

    if (ind == 0 && bases==0)
        return dp[ind][bases]=1;


    if(dp[ind][bases]!=-1)
    return dp[ind][bases];
    

    lli sum = 0;


    if(bases!=0)
    sum += (getways(ind - 1, bases - 1, primes) * ifac[primes[ind - 1].second - 1]%MOD) % MOD;

    sum += (getways(ind - 1, bases, primes) * ifac[primes[ind - 1].second]%MOD) % MOD;

    return dp[ind][bases]=sum;
}

int main()
{

   

    cin >> n;

    vector<lli> nums(2 * n);

    vector<pair<lli, lli>> modified;
    vector<pair<lli, lli>> primes;
    vector<pair<lli, lli>> composites;

    for (lli i = 0; i < 2 * n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());


    sieve();
    precomputeFactorial(n);

    memset(dp,-1,sizeof(dp));

    for (lli i = 0; i < 2 * n; i++)
    {
        if (modified.size() > 0 && (modified.back().first == nums[i]))
            modified.back().second++;

        else
            modified.push_back({nums[i], 1});
    }

    for (lli i = 0; i < modified.size(); i++)
    {
        lli num = modified[i].first;
        if ((num == 1) || (smallestprimedivisor[num] != num))
        {
            composites.push_back(modified[i]);
        }
        else
        {
            primes.push_back(modified[i]);
        }
    }

    
        // for (lli i = 0; i < primes.size(); i++)
        // {
        //     cout<<primes[i].first<<" "<<primes[i].second<<"\n";
        // }

    if (primes.size() < n)
    {
        cout << 0 << '\n';
    }
    else
    {

        lli sum = fac[n];

        for (lli i = 0; i < composites.size(); i++)
        {
            sum = (sum * ifac[composites[i].second]) % MOD;
        }

        lli ways = getways(primes.size(), n, primes);

        //cout << ways << "\n";

        sum = (sum * ways) % MOD;

        cout << sum << "\n";
    }
}