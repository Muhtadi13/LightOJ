#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 1000000007

using namespace std;

int main()
{
    lli t;
    cin >> t;
    lli ff;
    ff = t;

    vector<lli> fact(12);

    fact[0]=1;

    for(lli j=1;j<12;j++)
    {
        fact[j]=j*fact[j-1];

    }

    while (t--)
    {

       

        string s;
        cin >> s;
        lli n;
        cin >> n;

        lli sz = s.size();
         vector<lli> v(sz);

        for (lli j = 0; j < sz; j++)
        {
            v[j] = s[j] - '0';
        }

        lli k = (1 << sz);

        lli dp[k + 1][n + 1];
        //memset(dp,0,sizeof(dp));
        for(lli i=0;i<=k;i++)
        {
            for(lli j=0;j<=n;j++)
            {
                dp[i][j]=0;
            }
        }
        dp[0][0]=1;

        

        for (lli mask = 1; mask < k; mask++)
        {
            for (lli i = 0; i <= sz; i++)
            {

                if (mask & (1 << i))
                {
                    for (lli j = 0; j < n; j++)
                    {
                        dp[mask][(10*j+v[i]) % n] += dp[mask ^ (1 << i)][j];
                    }
                }
            }
        }
        vector<lli> cnt(10);

        for(lli j=0;j<sz;j++)
        {
            cnt[v[j]]++;
        }

        lli ans=dp[k - 1][0];

        for(lli j=0;j<10;j++)
        {
            if(cnt[j]>1)
            ans/=fact[cnt[j]];
        }

        cout<<"Case "<<ff-t<<": ";

        cout <<ans<<"\n";
    }
}