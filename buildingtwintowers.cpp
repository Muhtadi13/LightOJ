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
        lli n, m;
        cin >> n;
        vector<lli> v(n);
        lli mx = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mx += v[i];
        }
        lli dp[2][mx + 2];
        memset(dp, -1, sizeof(dp));
        dp[0][0]=0;

        lli now = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= mx; j++)
            {
                if(dp[1-now][j]==-1)
                continue;

                dp[now][j] = max(dp[now][j], dp[1 - now][j]);
                dp[now][abs(j - v[i])] = max(dp[now][abs(j - v[i])], max(dp[1 - now][abs(j - v[i])], dp[1 - now][j] + v[i]));
                if (j + v[i] <= mx)
                    dp[now][j + v[i]] = max(dp[now][j + v[i]], max(dp[1 - now][j + v[i]], dp[1 - now][j] + v[i]));
            }
            now = 1 - now;
        }

        lli ans=dp[1-now][0]/2;

        cout << "Case " << ff - t << ": ";

        if(ans==0)
        cout<<"impossible\n";

        else
        cout<<ans<<"\n";

        // for (int i = 0; i <= mx; i++)
        // {
        //     cout << dp[0][i] << " " << dp[1][i] << "\n";
        // }
        // cout << "\n";
    }
}