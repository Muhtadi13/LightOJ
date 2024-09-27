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
        lli n;

        cin >> n;
        lli f=1;
        
        if(n<0)
            f=0;
        
        n=abs(n);

        cout << "Case " << ff - t << ": ";

        vector<lli> p = getPrimeFactorization2(n);
       

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

        lli mx=0;

        for (auto u : fir)
        {
           mx=__gcd(mx,u.second);
        }
        
        if(f==0)
        {
            while(mx%2==0)
                mx/=2;
        }

        cout << mx << "\n";
    }
}