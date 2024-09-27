#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;
string s;
lli n;

lli pal[61][61];
lli dp[1001];

lli cntpali(lli start,lli fin)
{
    
    if(start>fin)
    {
       
        return pal[start][fin]=0;


    }

    if(start==fin)
    return pal[start][fin]=1;


    if(pal[start][fin]!=-1)
    return pal[start][fin];

    /* when s[st]==s[fin]
    1.include s[st] s[fin] in pal
        so 1+dp(st+1,fin-1)

    2.exclude one (subtract twice counted part)
        so dp(st+1,fin) + dp(st,fin-1) - dp(st+1,fin-1)

    since sum so 1+dp(st+1,fin) + dp(st,fin-1)



     when s[st]!=s[fin]

     1.only one case
     dp(st+1,fin) + dp(st,fin-1) - dp(st+1,fin-1)

    */
 

    lli sum=0;
    if(s[start]==s[fin])
    {  
        sum++;
    }
    else
    {
        sum-=cntpali(start+1,fin-1);
    }

    sum+=cntpali(start+1,fin);
    sum+=cntpali(start,fin-1);  
        
    return pal[start][fin]=sum;
    

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
        
        cin>>s;
        n=s.size();

        lli q=cntpali(0,n-1);
        
          cout << "Case " << ff - t << ": ";

        cout<<q<<"\n";

    }
}