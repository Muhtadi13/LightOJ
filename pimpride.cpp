#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1000000009LL
#define MOD 1000000007

using namespace std;

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

        vector<vector<lli>> nums(n, vector<lli>(n));

        for (lli i = 0; i < n; i++)
        {

            for (lli j = 0; j < n; j++)
            {
                cin >> nums[i][j];
            }
        }

        cout << "Case " << ff - t << ": ";

        lli dp[1 << n + 1];

        for (lli j = 0; j <= (1 << n); j++)
        {
            dp[j] = MAX;
        }

        dp[0]=0;

        for (lli mask = 0; mask < (1 << n); mask++)
        {

            for (lli i = 0; i < n; i++)
            {
                if ((mask & (1 << i) )== 0)
                    continue;

                lli sum = 0;
                //cout<<i<<"\n";

                for (lli j = 0; j < n; j++)
                {
                    if (((mask & (1 << j)) == 0))
                        continue;

                    sum += nums[i][j];
                }
                

                dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + sum);
            }
        }
        //  for (lli j = 0; j <= (1 << n); j++)
        // {
        //     cout<<dp[j]<<"\n";
        // }

        cout << dp[(1 << n) - 1] << "\n";
    }
}