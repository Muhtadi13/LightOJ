
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
        cin >> n >> m;

        lli adj[n + 1];
        lli dp[n + 1][n + 1];
        lli sum = 0;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = MOD;
            }
            adj[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            lli x, y, w;
            cin >> x >> y >> w;

            adj[x]++;
            adj[y]++;
            dp[x][y] = min(w,dp[x][y]);
            dp[y][x] =min(w,dp[y][x]);
            dp[x][x] = 0;
            dp[y][y] = 0;
            sum += w;
        }

        lli fin = 0LL;
        lli mx = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((adj[i] % 2) == 1)
            {
                fin |= (1 << (i - 1));
                mx = i;
            }
        }
        // cout<<fin<<mx<<"dfgdg\n";

        // lli shortest[n+1][n+1];

        for (lli k = 1; k <= n; k++)
        {
            for (lli i = 1; i <= n; i++)
            {
                for (lli j = 1; j <= n; j++)
                {
                    if (dp[i][k] == MOD || dp[k][j] == MOD)
                        continue;

                    if (dp[i][j] > dp[i][k] + dp[k][j])
                        dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }

        lli shortest[(1LL << 15) + 1];
        shortest[0] = 0;

        for (lli mask = 1; mask < (1LL << mx); mask++)
        {
            if ((__builtin_popcount(mask) % 2) == 1)
                continue;
            shortest[mask] = MOD;

            for (int i = 0; i < mx; i++)
            {
                if ((mask & (1LL << i)) == 0)
                    continue;

                for (int j = i + 1; j < mx; j++)
                {
                    if ((mask & (1LL << j)) == 0)
                        continue;

                    lli cost = shortest[(mask ^ (1LL << i)) ^ (1LL << j)] + dp[i + 1][j + 1];

                    if (shortest[mask] > cost)
                        shortest[mask] = cost;
                    // cout<<dp[i+1][j+1]<<"\n";
                }
            }
        }
        cout << "Case " << ff - t << ": ";

        cout << sum + shortest[fin] << "\n";
    }
}