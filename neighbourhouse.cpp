#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 1000000007

using namespace std;

lli n;

lli dp[1001][2][2];

vector<lli> sell(MAX);

lli luv(lli house, lli isnotified,lli lastnotified)
{
    if(house==n-1)
    {
        if(isnotified==1 || lastnotified==1)
        {
            return 0;
        }
        return sell[house];
        
    }
    
    if(dp[house][isnotified][lastnotified]!=-1)
    return dp[house][isnotified][lastnotified];


   lli sum=0;
    if (isnotified == 0)
    {
        if(house==0)
        lastnotified=1;

        sum=luv(house+1,1,lastnotified)+sell[house];

        if(house==0)
        lastnotified=0;

        sum=max(sum,luv(house+1,0,lastnotified));
       

    }
    else
    {
         sum=luv(house+1,0,lastnotified);   

    }
    return dp[house][isnotified][lastnotified]=sum;
}

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;

    while (t--)
    {

        memset(dp, -1, sizeof(dp));
       
        cin>>n;
        

        for(lli i=0;i<n;i++)
        {
            cin>>sell[i];
        }
       
         cout << "Case " << ff - t << ": ";

        cout<<luv(0,0,0)<<"\n";
    }
  
}