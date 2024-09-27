#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;
string s;
lli n;

lli pal[1001][1001];
lli dp[1001];

lli ispali(lli start,lli fin)
{

    if(start==fin-1)
    {
        pal[start][start]=1;
        pal[fin][fin]=1;

        if(s[start]==s[fin])
        return pal[start][fin]=1;

        else
        return pal[start][fin]=0;


    }

    if(start==fin)
    return pal[start][fin]=1;

    if(pal[start][fin]!=-1)
    return pal[start][fin];

    lli f=ispali(start+1,fin);
    lli l=ispali(start,fin-1);



    if(s[start]==s[fin])
    {
        return pal[start][fin]=ispali(start+1,fin-1);
    }

   
        
    return pal[start][fin]=0;
    

}

lli partition(lli start)
{
    if(start==n)
    return 0;

    if(dp[start]!=-1)
    return dp[start];

    lli ans=INT_MAX;
    for(lli i=start;i<n;i++)
    {
        if(pal[start][i]!=1)
        continue;


        ans=min(ans,1+partition(i+1));
    }

    return dp[start]=ans;
}

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;
    
    while (t--)
    {
        s.clear();
        memset(pal,-1,sizeof(pal));
        memset(dp,-1,sizeof(dp));
        cin>>s;
        n=s.size();

        lli q=ispali(0,n-1);
        

        // for(lli i=0;i<s.size();i++)
        // {
        //     for(lli j=0;j<s.size();j++)
        //     {
        //         cout<<pal[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
          cout << "Case " << ff - t << ": ";

        cout<<partition(0)<<"\n";

    }
}