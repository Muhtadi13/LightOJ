#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 102LL
#define MOD 1000000007
using namespace std;

// vector<lli> cnt[MAX];
// vector<lli> v[MAX];
// vector<lli> maxuse[MAX];
// vector<lli> found[100002]

//lli dp[MAX][100002];

// lli solve(lli n,lli sum)
// {
//     if((n==0) && (sum>0))
//     {
//         return 0;
//     }

//     if(sum==0)
//     {

//     }
//     lli sum=0;
//     sum+=solve(n-1,sum);
//     if(cnt[n]<maxuse[n])
//     {
//         sum+=solve(n-1,sum-v[n]); 
//         cnt[n]++;

//     }

    
// }




int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    lli t;
    cin >> t;

    lli ff = t;
    while (t--)
    {
        lli n,m;
        cin>>n>>m;

        vector<lli> coinval(n);

        vector<lli> upbound(n);

        for(lli j=0;j<n;j++)
        {
            cin>>coinval[j];
        }
        for(lli j=0;j<n;j++)
        {
            cin>>upbound[j];
        }
        //vector<vector<lli>> dp(n+1, vector<lli>(m+1));
        vector<lli> dp(m+1);
        dp[0]=1;
        lli cnt=0;


        for(lli i=1;i<=n;i++)
        {
             vector<lli> howmany(m+1);//howmany till that index is used
             
            for(lli j=coinval[i-1];j<=m;j++)
            {
                // if(dp[j]==1)
                // cnt++;
               
            

                if(dp[j]==0 && dp[j-coinval[i-1]]!=0 && upbound[i-1]>howmany[j-coinval[i-1]])
                {
                    //if(dp[j-coinval[i-1]]==coinval[i-1])
                    //upbound[i-1]--;

                    dp[j]=1;
                    howmany[j]=howmany[j-coinval[i-1]]+1;
                    
                    cnt++;
                }
                //cnt--;
                
                // else
                // dp[j]=0;
            
                //cout<<dp[j]<<" ";
            }
           // cout<<"\n";

        }
        
        
        cout << "Case " << ff - t << ": ";

        cout<<cnt<<"\n";





    }
}