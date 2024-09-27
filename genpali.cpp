#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;
string s;
lli n;

lli pal[102][102];
//lli dp[1001];

lli operation(lli start,lli fin)
{

    if(start>fin)
    {
        return 0;
       


    }

    if(start==fin)
    return pal[start][fin]=0;

    if(pal[start][fin]!=-1)
    return pal[start][fin];

    lli f=1+operation(start+1,fin);
    lli l=1+operation(start,fin-1);

    lli ans=min(f,l);



    if(s[start]==s[fin])
    {
        lli ga=operation(start+1,fin-1);
        ans=min(ans,ga);
        
        
    }

   
        
    return pal[start][fin]=ans;
    

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
        //memset(dp,-1,sizeof(dp));
        cin>>s;
        n=s.size();

         cout << "Case " << ff - t << ": ";

        cout<<operation(0,n-1)<<'\n';


    }
}