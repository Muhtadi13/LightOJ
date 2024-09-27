#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 10056
using namespace std;

lli table[MAX][MAX];

lli nCr(lli n)
{
    table[1][1] = 1;
    for (lli i = 0; i <= n; i++)
    {
        for (lli j = 0; j <= i; j++)
        {
            if ((j == 0) || (j == i))
                table[i][j] = 1;

            else
                table[i][j] = (table[i - 1][j - 1]%MOD+table[i-1][j]%MOD)%MOD;
        }
    }
}
lli dp[MAX+1];

lli solve(lli n)
{
    if(n<=1)
    return dp[1]=1;

    if(dp[n]!=0)
    {
        
        return dp[n];
    }

    lli cnt=0;
    for(lli i=1;i<=n;i++)
    {
        cnt=(cnt+((table[n][i]%MOD)*(solve(n-i)%MOD))%MOD)%MOD;


    }   
    return dp[n]=cnt;
}

int main()
{
    lli t;
    cin >> t;
    lli ff = t;
    nCr(MAX-1);
    for(lli j=0;j<=MAX;j++)
        {
            dp[j]=0;
        }
    lli ans=solve(1001);
    while (t--)
    {
        lli n;
        cin>>n;

        

        cout<<"Case "<<ff-t<<": "<<dp[n]<<"\n";
    }
}