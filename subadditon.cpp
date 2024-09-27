#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;

int main()
{
    lli t;
    cin >> t;

    while (t--)
    {
        lli n;
        cin >> n;
        lli ans = 1;

        vector<lli> v(n + 1);

        for (lli j = 1; j <= n; j++)
        {
            cin >> v[j];
        }

        sort(v.begin(), v.end());
        if (v[1] != 1)
            ans = 0;

        else
        {
            
           vector<lli> prefsum(n + 1, 0);

            for (lli j = 1; j <= n; j++)
            {
                prefsum[j] = prefsum[j - 1] + v[j];
            }
            for(lli j=2;j<=n;j++)
            {
                if(prefsum[j-1]<v[j])
                {
                    ans=0;
                    break;
                }

            }
        }


       
        if (ans == 0)
            cout << "NO\n";

        else
            cout << "YES\n";
    }
}