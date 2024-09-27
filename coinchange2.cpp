#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli t;
    cin >> t;

    lli ff = t;
    while (t--)
    {
        lli n, k;

        cin >> n >> k;

        vector<lli> coinval(n);

        for (lli j = 0; j < n; j++)
        {
            cin >> coinval[j];
        }

        vector<vector<lli>> dp(n+1, vector<lli>(k+1));
        dp[0][0]=1;

        for (lli i = 1; i <= n; i++)
        {
            // if (i == 0)
            //     dp[i][0] = 1;

           
                //dp[i][0] = 1;

                for (lli j = 0; j <= k; j++)
                {
                    dp[i][j]=( dp[i][j]+dp[i-1][j])%MOD;//didnot use ith coin
                    
                    if (j - coinval[i-1] >= 0)
                    {
                        dp[i][j] = ( dp[i][j]+dp[i][j-coinval[i-1]])%MOD;//since used ith coin now that means we have used it before
                    }
                    //cout<<dp[i][j]<<" ";
                    
                }
                //cout<<"\n";
            
        }
        ////time efficient approach
        // for (lli i = 1; i <= n; i++)
        // {
           

        //         for (lli j = coinval[i]; j <= k; j++)
        //         {
        //            dp[0][j] = ( dp[0][j]+dp[0][j-coinval[i-1]])%MOD;
                    
        //         }
        //         //cout<<"\n";
            
        // }
        //cout<<dp[0][k];

        cout << "Case " << ff - t << ": ";

        cout<<dp[n][k]<<"\n";
    }
}

