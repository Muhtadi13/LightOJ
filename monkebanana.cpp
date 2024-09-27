#include <bits/stdc++.h>
#define lli long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    int ind=t;
    while(t--)
    {
        lli n;
        cin>>n;

        vector<vector<lli> >dp(2*n-1);
        vector<vector<lli> >monke(2*n-1);


        for(lli i=0;i<n;i++)
        {
            for(lli j=0;j<=i;j++)
            {
                lli x;
                cin>>x;
                monke[i].push_back(x);

            }
        }
        for(lli i=n;i<2*n-1;i++)
        {
            for(lli j=0;j<2*n-i-1;j++)
            {
                lli x;
                cin>>x;
                monke[i].push_back(x);

            }
        }
        dp[0].push_back(monke[0][0]);
        

         for(lli i=1;i<n;i++)
        {
            for(lli j=0;j<=i;j++)
            {
                if(j==0)
                {
                    
                    dp[i].push_back(dp[i-1][0]+monke[i][j]);
                }
                else if(j==i)
                {
                    
                    dp[i].push_back(dp[i-1][j-1]+monke[i][j]);
                }

                else
                {
                    dp[i].push_back(max(dp[i-1][j-1],dp[i-1][j])+monke[i][j]);

                }

            }
        }
         for(lli i=n;i<2*n-1;i++)
        {
            for(lli j=0;j<i;j++)
            {
                
                dp[i].push_back(max(dp[i-1][j],dp[i-1][j+1])+monke[i][j]);

            }
        }
        // for(lli i=0;i<n;i++)
        // {
        //     for(lli j=0;j<=i;j++)
        //     {
        //         cout<<monke[i][j];

        //     }
        //     cout<<"\n";
        // }
        // for(lli i=n;i<2*n-1;i++)
        // {
        //     for(lli j=0;j<2*n-i-1;j++)
        //     {
        //         cout<<monke[i][j];

        //     }
        //     cout<<"\n";
        // }
        // for(lli i=0;i<n;i++)
        // {
        //     for(lli j=0;j<=i;j++)
        //     {
        //         cout<<dp[i][j]<<" ";

        //     }
        //     cout<<"\n";
        // }
        // for(lli i=n;i<2*n-1;i++)
        // {
        //     for(lli j=0;j<2*n-i-1;j++)
        //     {
        //         cout<<dp[i][j];

        //     }
        //     cout<<"\n";
        // }


        cout<<"Case "<<ind-t<<": "<<dp[2*n-2][0]<<"\n";


    }
}

