#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200005
#define MOD 1000000007

using namespace std;



vector<plli> range(MAX);
lli dp[MAX][2];
lli n;

lli cntremv(lli pos,lli start)
{
    if(pos==n-1)
    {
        if(start==1)
        return MOD;

        return 0;
        // if(start==1)
        // return dp[pos][start]=MOD;

        // else return dp[pos][start]=0;


    }

    if(dp[pos][start]!=MOD)
    return dp[pos][start];

    lli mn=MOD;
    if(start==1)
    {
        for(lli i=pos+1;i<=n;i++)
        {
            if(range[i].first<=range[pos].second)
            {
                mn=min(mn,cntremv(i,0)+(i-pos-1));
            }
        }
    }
    else
    {
        for(lli i=pos+1;i<=n;i++)
        {
            if(range[i].first>range[pos].second)
            {
                mn=min(mn,cntremv(i,1)+(i-pos-1));
            }
        }

    }
    //cout<<pos<<" "<<start<<" "<<mn<<"\n";
    return dp[pos][start]=mn;
}
bool comp(plli p1,plli p2)
{
    if(p1.second==p2.second)
    return p1.first<p2.first;
    return p1.second<p2.second;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        //lli n;
        cin>>n;
        for(lli i=0;i<=n;i++)
        {
            dp[i][0]=MOD;
            dp[i][1]=MOD;
        }

        //vector<plli> v(n);
        for(lli i=0;i<n;i++)
        {
            lli x,y;
            cin>>x>>y;
            range[i]={x,y};
        }

        sort(range.begin(),range.begin()+n,comp);

         for(lli i=0;i<n;i++)
        {
            cout<<range[i].first<<" "<<range[i].second<<"\n";
         
        }
        cout<<min(cntremv(0,0)+1,cntremv(0,1))<<"\n";

    }
}