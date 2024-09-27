#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
using namespace std;

int main()
{
    lli t;
    cin >> t;
    lli ff=t;
    while(t--){

        lli n;
        cin>>n;

        vector<lli> dresses(n);

        vector<vector<lli>> dp(n,vector<lli> (n,0));

        for(lli j=0;j<n;j++)
        {
            cin>>dresses[j];
        }

        for(lli i=n-1;i>=0;i--)
        {
            dp[i][i]=1;
            for(lli j=i+1;j<n;j++)
            {
                dp[i][j]=dp[i][j-1]+1;

                for(lli k=i;k<j;k++)
                {
                    if(dresses[k]==dresses[j])
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j-1]);
                }

            }
        }
        

        cout<<"Case "<<ff-t<<": "<<dp[0][n-1]<<"\n";



    }
}


