#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;

lli dp2[MAX][2];

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;
    while (t--)
    {
        lli n, q;

        cin >> n >> q;

        vector<lli> nums(n);

        for (lli j = 0; j < n; j++)
        {
            cin >> nums[j];
        }

        cout<<"Case "<<ff-t<<":\n";

        while (q--)
        {
            lli d, m;
            cin >> d >> m;

            lli dp[n + 1][m + 1][d];

            for(lli i=0;i<=n;i++)
            {
                for(lli j=0;j<=m;j++)
                {
                    for(lli k=0;k<d;k++)
                    {
                        dp[i][j][k]=0;
                    }
                }
                dp[i][0][0]=1;
            }



            for (lli i = 1; i <= n; i++)
            {
                for (lli j = 1; j <= m; j++)
                {
                    for (lli k = 0; k < d; k++)
                    {
                        dp[i][j][k] += dp[i - 1][j][k];
                        dp[i][j][((k + nums[i-1]) % d + d) % d] += dp[i - 1][j - 1][k];
                    }
                }
            }


            cout<<dp[n][m][0]<<"\n";
        }
    }
}