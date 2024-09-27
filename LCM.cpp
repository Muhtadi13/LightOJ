#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1e12 + 6
#define MOD 1000000007LL

using namespace std;



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



int main()
{

    lli t;
    cin >> t;
    lli ff = t;

    while (t--)
    {
        lli n, m, l;

        cin >> n >> m >> l;

        cout << "Case " << ff - t << ": ";

        lli prod = n * m;
        lli g = __gcd(n, m);

        prod = prod / g;

        if ((l % prod) != 0)
        {
            cout << "impossible\n";
            continue;
        }

       

        vector<lli> p = getPrimeFactorization2(prod);
        vector<lli> num = getPrimeFactorization2(l);

        lli idx = 0;
        lli cnt = 1;

        

        map<lli, lli> fir;

        while (idx+1 < p.size())
        {
            if (p[idx] == p[idx + 1])
            {
                cnt++;
            }
            else
            {

                fir.insert({p[idx], cnt});
                cnt = 1;
            }
            idx++;
        }
        if(idx<p.size())
        fir.insert({p[idx], cnt});

        map<lli, lli> sec;
        idx = 0;
        cnt = 1;

        while (idx+1 < num.size())
        {
            if (num[idx] == num[idx + 1])
            {
                cnt++;
            }
            else
            {

                sec.insert({num[idx], cnt});
                cnt = 1;
            }
            idx++;
        }
        if(idx<num.size())
        sec.insert({num[idx], cnt});

        map<lli, lli> ans;

        for (auto u : sec)
        {
            if (u.second > fir[u.first])
            {
                ans[u.first] = u.second;
            }
        }

        lli a = 1;

        for (auto u : ans)
        {
            for (lli j = 0; j < u.second; j++)
                a *= u.first;
        }

        cout << a << "\n";
    }
}