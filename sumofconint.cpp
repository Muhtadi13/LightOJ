#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1e7 
#define MOD 1000000007LL

using namespace std;

vector<bool> smallestprimedivisor(MAX + 1);
vector<lli> primes;



void sieve()
{

    for (lli i = 0; i <= MAX; i++)
        smallestprimedivisor[i] = false;

    for (lli i = 2; i * i <= MAX; i++)
    {
        if (smallestprimedivisor[i] == false)
        {

            for (lli j = i * 2; j <= MAX; j += i)
            {
                if (smallestprimedivisor[j] == false)
                    smallestprimedivisor[j] = true;
            }
        }
    }

    for (lli i = 2; i <= MAX; i++)
    {
        if (smallestprimedivisor[i] == false)
            primes.push_back(i);
    }
}



int main()
{
    sieve();

    lli t;
    cin >> t;
    lli ff = t;

    while (t--)
    {
        lli n;

        cin >> n;
        lli ans = 1;

        while (n % 2 == 0)
        {

            n = n / 2;
        }

        for (lli i = 0; i<primes.size(); i++)
        {
            if(primes[i] * primes[i] > n)
            break;

            lli cnt = 0;
            lli x = primes[i];
            while (n % x == 0)
            {
                cnt++;
                n = n / x;
            }

            ans=ans*(cnt+1);
        }

        if(n>1)
        {
            ans=ans*2;
        }

        cout << "Case " << ff - t << ": ";

        cout << ans-1 << "\n";
    }
}