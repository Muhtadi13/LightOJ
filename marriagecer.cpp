#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009LL
#define lli long long
#define MAX 15

int main()
{
    int t,ff;
    cin>>t;
    ff=t;

    while(t--)
    {
        lli n;cin>>n;

        vector<vector<lli>> prio(n+1,vector<lli>(n+1));
        vector<lli> luv(n);
        vector<lli> dp(1<<n+1);

        for(lli i=0;i<n;i++)
        {
            for(lli j=0;j<n;j++)
            {
                cin>>prio[i+1][j+1]; 
            }
        }


        for(lli mask=1;mask<(1<<n);mask++)
        {//denotes the men i have chosen
            for(lli i=0;i<n;i++)
            {//the man to choose ith woman
                if((mask&(1<<i))==0)
                continue;

               lli ind=__builtin_popcount(mask);

                dp[mask]=max(dp[mask],dp[(mask^(1<<i))]+prio[i+1][ind]);

                
            }
        }

        cout<<"Case "<<ff-t<<": "<<dp[(1<<n)-1]<<"\n";
    }
}