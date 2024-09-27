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
        // {
        //      memset(dp, -1, sizeof(dp));
        //     num.clear();

        lli n;

        cin >> n;
        vector<lli> num(n);

        for (lli i = 0; i < n; i++)
        {
            cin >> num[i];
        }

        double dp[101];
        for (lli i = 0; i < n; i++)
            dp[i] = num[i];

        for (lli i = n - 2; i >= 0; i--)
        {
            if (i >= n - 6)
            {
                for (lli j = i + 1; j < n; j++)
                {
                    dp[i] += dp[j] / (1.0 * (n - i - 1));
                }
            }
            else
            {
                for (lli j = i + 1; j <= i + 6; j++)
                {
                    dp[i] += dp[j] / (6.0);
                }
            }
        }

        cout << "Case " << ff - t << ": ";

        //cout << setprecision(15) << dp[0] << "\n";
        printf("%.10f\n",dp[0]);
    }
}