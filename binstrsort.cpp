#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 300005
#define COST 1e12

using namespace std;
string s;
lli n;

lli dp[MAX][2];

lli coins(lli ind,lli ones,lli prev)
{
    if(ind==n)
    return 0;



    if(prev==1 && s[ind]=='0')
    {
        if(dp[ones][0]!=-1)
        return dp[ones][0];

        lli fir=coins(ind+1,ones,0)+ones*COST;
        lli sec=coins(ind+1,ones,1)+COST+1;

        return dp[ones][0]=min(fir,sec);


    }

    if(dp[ones][1]!=-1)
    return dp[ones][1];

    

    if(s[ind]=='0')
    {

        lli fir=coins(ind+1,ones,0)+ones*COST;
        lli sec=coins(ind+1,ones,0)+COST+1;

        
        
        //cout<<ind<<" "<<0<<" "<<fir<<" "<<sec<<"\n";
        return dp[ones][1]=min(fir,sec);
    }
    else{
        // if(dp[ones][1]!=-1)
        // return dp[ones][1];
        lli fir=coins(ind+1,ones+1,1);
        lli sec=coins(ind+1,ones,1)+COST+1;
        //cout<<ind<<" "<<1<<" "<<fir<<" "<<sec<<"\n";
        return dp[ones][1]=min(fir,sec);

    }
    
}

int main()
{
    lli t;
    cin >> t;

    while (t--)
    {
        s.clear();
        cin>>s;
        n=s.size();
        for(lli i=0;i<=n;i++)
        {
            dp[i][0]=-1;
            dp[i][1]=-1;
        }

        cout<<coins(0,0,0)<<"\n";
    }
}