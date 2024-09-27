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
    lli ff;
    ff = t;
    while (t--)
    {
        lli n;
        lli d;

        cin >> n;
        cin >> d;

        vector<lli> nums(n);

        for (lli j = 0; j < n; j++)
        {
            cin >> nums[j];
        }

        cout << "Case " << ff - t << ": ";

        lli dp[n + 1][d + 1];

        for (lli i = 0; i <= n; i++)
        {
            for (lli j = 0; j <= d; j++)
            {

                dp[i][j] = 0;
            }
            dp[i][1] = 1;
        }
       
        for (lli k = 2; k <= d; k++)
        {

            for (lli i = 0; i < n; i++)
            {
                for (lli j = 0; j < n; j++)
                {

                    if (abs(nums[i] - nums[j]) <= 2)
                        dp[i][k] += dp[j][k - 1];
                }
            }
        }
        

        lli ans = 0;

        for (lli i = 0; i < n; i++)
        {
            ans += dp[i][d];
        }

        cout << ans << "\n";
    }
}