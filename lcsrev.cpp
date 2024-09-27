#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200005
#define MOD 1000007LL

using namespace std;

int main()
{
    lli t;
    cin >> t;
    lli ff = t;

    while (t--)
    {
        lli n,m;
        //cin >> n;
        string s1;
        string s2;

        cin>>s1>>s2;
        n=s1.size();
        m=s2.size();

        lli dp[n+1][m+1];
        lli cnt[n+1][m+1];
        

        for(int i=0;i<=n;i++)
        {
            //dp[0][i]=0;
            dp[i][0]=0;
            //cnt[0][i]=0;
            cnt[i][0]=0;
            
        }
         for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
            //dp[i][0]=0;
            cnt[0][i]=0;
            //cnt[i][0]=0;
            
        }

        
        //cnt[0][0]=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;

                    if(cnt[i-1][j-1]==0)
                    cnt[i][j]=1;

                    else
                    cnt[i][j]=cnt[i-1][j-1];
                }
                else
                {
                    if(dp[i-1][j]==dp[i][j-1])
                    {
                        dp[i][j]=dp[i-1][j];
                        cnt[i][j]=(cnt[i-1][j]+cnt[i][j-1])%MOD;

                        if(dp[i][j]==dp[i-1][j-1])
                        {
                            cnt[i][j]=(cnt[i][j]+MOD-cnt[i-1][j-1])%MOD;
                        }
                    }
                    else if(dp[i-1][j]>dp[i][j-1])
                    {
                        dp[i][j]=dp[i-1][j];
                        cnt[i][j]=cnt[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=dp[i][j-1];
                        cnt[i][j]=cnt[i][j-1];
                    }
                }
            }
        }
        cout << "Case " << ff - t << ": ";

        if(dp[n][m]==0)
        cout<<1<<"\n";

        else
        cout<<(cnt[n][m]+MOD)%MOD<<"\n";

        

        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";

        //  for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     {
        //         cout<<cnt[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
    }
    
}