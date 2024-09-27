#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 101LL
#define MOD 1000000007

using namespace std;
// string s;
// lli n;

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;

    while (t--)
    {

        lli n;

        cin >> n;
        vector<lli> num(n);

        lli neg = 0;
        lli sum = 0;

        for (lli i = 0; i < n; i++)
        {
            cin >> num[i];

            if (num[i] < 0)
                neg++;

            sum +=abs( num[i]);
        }
        cout << "Case " << ff - t << ": ";

        if (n == neg)
        {
            cout << "inf\n";
        }

        else
        {
            lli den=n-neg;

            lli g=__gcd(sum,den);

            sum/=g;
            den/=g;

            cout <<sum<<"/" << den << "\n";
           
        }
    }
}