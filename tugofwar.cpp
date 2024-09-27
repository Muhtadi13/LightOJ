#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200005
#define MOD 1000000007LL

using namespace std;

int main()
{
    lli t;
    cin >> t;
    lli ff = t;

    while (t--)
    {
        lli n;
        cin >> n;
        vector<lli> v(n + 1);
        lli mx = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            mx += v[i];
        }

        bool dp[2][mx + 2][3];
        memset(dp, 0, sizeof(dp));

        dp[0][0][0] = 1;
        lli now = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= mx; j++)
            {
                dp[now][j][0] = 0;
                dp[now][j][1] = 0;
                dp[now][j][2] = 0;
            }
            for (int j = 0; j <= mx; j++)
            {
                // dp[now][abs(j-v[i])]=0;
                dp[now][abs(j - v[i])][1]|=dp[1 - now][j][0];
                
                dp[now][abs(j - v[i])][1]|=dp[1 - now][j][0];

                if (j + v[i] <= mx)
                {
                    // dp[now][j+v[i]]=0;
                    dp[now][j + v[i]][1]|= dp[1 - now][j][0];
                    dp[now][j + v[i]][1]|= dp[1 - now][j][0];
                    
                }
            }
            now = 1 - now;
        }
        lli ans = 0;
        // for (int j = 0; j <= mx; j++)
        // {
        //     cout << dp[1 - now][j][0] << " ";
        // }
        // cout << "\n";
        lli val=n%2;



        for (int j = 0; j <= mx; j++)
        {
            if (dp[1 - now][j][val] == 1)
            {
                ans = j;
                break;
            }
        }
        cout << "Case " << ff - t << ": ";

        cout << (mx - ans) / 2 << " " << mx - (mx - ans) / 2 << "\n";
    }
}