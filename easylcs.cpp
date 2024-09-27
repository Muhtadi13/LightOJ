#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1000000009LL
#define MOD 1000000007

using namespace std;


string maximin(string a,string b)
{
	if(a.length()>b.length())
	return a;

	if(a.length()<b.length())
	{
		return b;
	}

	for(int i=0;i<a.length();i++)
	{
		if(a[i]<b[i])
		{
			return a;
		}
		if(a[i]>b[i])
		{
			return b;
		}
	}

	return a;
}

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;
    while (t--)
    {
        lli n1,n2;

        //cin >> n;

        string s1,s2;

        cin>>s1>>s2;

        n1=s1.size();
        n2=s2.size();


        string dp[n1+1][n2+1];

		lli ans[101][101];

        for(lli i=0;i<n1+1;i++)
        {
            dp[i][0]="";
			ans[i][0]=0;
        }
         for(lli i=0;i<n2+1;i++)
        {
            dp[0][i]="";
			ans[0][i]=0;
        }


		

        
        

        for(lli i=1;i<=n1;i++)
        {
            for(lli j=1;j<=n2;j++)
            {
				dp[i][j]=maximin(dp[i-1][j],dp[i][j-1]);
                
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=maximin(dp[i][j],dp[i-1][j-1]+s1[i-1]);
					ans[i][j]=ans[i-1][j-1]+1;
                    
                }
				
            }
        }

       
        // for(lli i=0;i<=n1;i++)
        // {
        //     for(lli j=0;j<=n2;j++)
        //     {
        //         cout<<dp[i][j]<<" ";

        //     }
        //     cout<<'\n';
            
        // }
		// for(lli i=0;i<=n1;i++)
        // {
        //     for(lli j=0;j<=n2;j++)
        //     {
        //         cout<<ans[i][j]<<" ";

        //     }
        //     cout<<'\n';
            
        // }



        // for(lli i=1;i<=n1;i++)
        // {
        //     for(lli j=1;j<=n2;j++)
        //     {
        //         if((s1[i-1]==s2[j-1]) && (dp[i][j]==dp[i-1][j-1]+1))
        //         {
        //             if((dp[i][j-1]==dp[i][j]) || (dp[i-1][j]==dp[i][j]))
        //             ans[dp[i][j]-1]=min(ans[dp[i][j]-1],s1[i-1]);

        //             // else
        //             // ans[dp[i][j]-1]=s1[i-1];
        //         }


        //     }

            
        // }

        //cout<<ans<<"\n";

		 cout<<"Case "<<ff-t<<": ";

		if(dp[n1][n2].length()==0)
        dp[n1][n2]=":(";

		
		cout<<dp[n1][n2]<<'\n';
    }
}









