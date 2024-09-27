#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 101LL
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

        lli b, k;

        cin >> b >> k;

        string s;
        cin >> s;

        lli n = s.size();

        vector<lli> num(n);

        for (lli i = 0; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                num[i] = s[i] - '0';

            else
                num[i] = (s[i] - 'A' + 10);
        }
        // reverse(num.begin(),num.end());

        // for (lli i = 0; i < n; i++)
        // {
        //     cout<<num[i]<<"jaja\n";
        // }

        lli dp[(1 << n) + 1][k + 1];

        for (lli mask = 0; mask < (1 << n); mask++)
        {
            for (lli i = 0; i <= k; i++)
            {
                dp[mask][i] = 0;
            }
        }

        dp[0][0] = 1;

        for (lli mask = 1; mask < (1 << n); mask++)
        {
            for (lli i = 0; i < n; i++)
            {
                if ((mask & (1 << i)) == 0)

                    continue;

                for (lli j = 0; j < k; j++)
                {
                    dp[mask][(j * b + num[n - i - 1]) % k] += dp[mask ^ (1 << i)][j];
                    // cout<<dp[mask^(1<<i)][j]<<"kfkfkf\n";
                }
            }
        }
        // for (lli mask = 0; mask < (1 << n); mask++)
        // {

        //     for (lli j = 0; j < k; j++)
        //     {
        //         cout << dp[mask][j] << " ";
        //     }
        //     cout << "\n";
        // }

        cout << "Case " << ff - t << ": ";

        printf("%d\n", dp[(1 << n) - 1][0]);
    }
}