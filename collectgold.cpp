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
        lli m, n;
        cin >> m >> n;

        vector<plli> golddragon;
        plli ini;

        for (lli i = 0; i < m; i++)
        {
            for (lli j = 0; j < n; j++)
            {
                char c;
                cin >> c;

                if (c == 'g')
                    golddragon.push_back({i, j});

                if (c == 'x')
                    ini = {i, j};
            }
        }

        lli sz = golddragon.size();
        //cout << sz << "\n";

        lli dp[sz+1][1 << (sz) + 1];

        for (lli i = 0; i < sz; i++)
        {
            for (lli j = 0; j <= (1 << (sz)); j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
  
        dp[0][0] = 0;

        for (lli mask = 1; mask < (1 << (sz)); mask++)
        {
            for (lli i = 0; i < sz; i++)
            {
                if ((mask & (1 << i)) == 0)
                    continue;

                lli mask2 = mask ^ (1 << i);
                if(mask2==0)
                {
                     lli check = max(abs(ini.second - golddragon[i ].second), abs(ini.first - golddragon[i].first));
                     if (check  < dp[i ][mask])
                    {
                        dp[i ][mask] = check;
                    }

                    continue;


                }

                for (lli j = 0; j < sz ; j++)
                {
                    if ((mask2 & (1 << j)) == 0)
                        continue;

                    lli check = dp[j][mask2] + max(abs(golddragon[j ].second - golddragon[i ].second), abs(golddragon[j ].first - golddragon[i].first));
                    
                    //cout << mask << " " << i << " " << check << "\n";
                    if (check  < dp[i ][mask])
                    {
                        dp[i ][mask] = check;
                       
                    }
                }
            }
        }

        lli ans = INT_MAX;
        for (lli i = 0; i < sz; i++)
        {
            plli ref = golddragon[i];
            lli check2 = max(abs(ini.second - ref.second), abs(ini.first - ref.first));

            ans = min(ans, dp[i][(1 << (sz)) - 1] + check2);
        }
         cout << "Case " << ff - t << ": ";
        if(ans==INT_MAX)
        ans=0;
        cout << ans << "\n";
    }
}
