#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 100001
#define MOD 1000000007

using namespace std;

double dp[MAX];

int main()
{
    dp[1] = 0.0;

    for (lli i = 2; i < MAX; i++)
    {
        lli cnt = 0;
        for (lli j = 1; j * j <= i; j++)
        {
            if (j == 1)
            {
                dp[i] = dp[j]+2.0;
                cnt += 2;
            }
            else
            {
                if ((i % j) == 0)
                {
                    dp[i]+=(dp[j]+dp[i/j]+2.0);
                    cnt+=2;
                }

            }
            if(j*j==i)
            {
                dp[i]-=(dp[j]+1.0);
                cnt--;
            }
        }
        dp[i]/=1.0*(cnt-1.0);
    }

    lli t;
    cin >> t;
    lli ff;
    ff = t;
    while (t--)
    {
        lli n;
        cin>>n;
        cout << "Case " << ff - t << ": ";
        cout<<setprecision(11)<<dp[n]<<"\n";
    }
}