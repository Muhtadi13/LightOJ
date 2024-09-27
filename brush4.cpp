#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 101LL
#define MOD 1000000007

using namespace std;
lli dp[(1 << 17)];
lli line[17][17];
lli n;

bool sameline(plli &p1, plli &p2, plli &p3)
{
    return (p1.first - p2.first) * (p3.second - p2.second) == (p1.second - p2.second) * (p3.first - p2.first);
}

lli val(lli mask)
{
    if (dp[mask] != -1)
        return dp[mask];

    if (__builtin_popcount(mask) == n)
        return dp[mask] = 0;

    if (__builtin_popcount(mask) >= n - 2)
        return dp[mask] = 1;

    lli mn = 8;
    for (lli i = 0; i < n; i++)
    {
        if ((mask & (1 << i)) != 0)
            continue;

        for (lli j = i + 1; j < n; j++)
        {
            if ((mask & (1 << j)) != 0)
                continue;

            lli ind = mask | line[i][j];
            mn = min(1 + val(ind), mn);
        }
        break;
    }
    return dp[mask] = mn;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    lli t;
    scanf("%d", &t);
    lli ff;
    ff = t;

    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        memset(line, 0, sizeof(line));

        string s;

        scanf("\n%d", &n);

        vector<plli> num(n);

        for (lli i = 0; i < n; i++)
        {
            lli x, y;
            scanf("%d %d", &x, &y);

            num[i] = {x, y};
        }
        if (n <= 2)
        {
            printf("Case %d: %d\n", ff - t, 1);
            continue;
        }

        for (lli i = 0; i < n; i++)
        {

            for (lli j = i + 1; j < n; j++)
            {
                // line[i][j] = 0;
                lli temp = 0;

                for (lli k = 0; k < n; k++)
                {
                    if (sameline(num[i], num[j], num[k]))
                        temp |= (1 << k);
                }
                line[i][j] = temp;
            }
        }
      

        printf("Case %d: %d\n", ff - t, val(0));
        //   for (lli mask = 0; mask < (1 << n); mask++)
        // {
        //     if(dp[mask]!=-1)
          

        //     cout << dp[mask] << " ";
        // }
        // cout << "\n";
    }
}