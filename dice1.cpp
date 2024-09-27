#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200005
#define MOD 100000007LL

using namespace std;



int main()
{
    lli t;
    cin >> t;
    lli ff = t;

    while(t--)
    {
        lli n,m,s;
        cin>>n>>m>>s;

        lli dp[2][s+2];
        lli csum[2][s+3];
        lli now=1;
        dp[0][0]=1;
        csum[0][0]=1;

        for(int i=1;i<=s;i++)
        {
            dp[0][i]=0;
            csum[0][i]=csum[0][i-1];

        }

        for(int i=1;i<=n;i++)
        {
            csum[now][0]=0;
            dp[now][0]=0;
            for(int j=1;j<=s;j++)
            {
                lli prev=0;
                if(j-m-1>=0)
                prev=csum[1-now][j-m-1];

                dp[now][j]=(csum[1-now][j-1]-prev+MOD)%MOD;
                csum[now][j]=(csum[now][j-1]+dp[now][j])%MOD;
            }
            now=1-now;
        }
          cout << "Case " << ff - t << ": ";

        cout<<dp[1-now][s]<<"\n";

        


    }
}