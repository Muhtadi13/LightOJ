#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;
vector<lli> num;
vector<lli> prepow(32);
lli n;

lli dp1[32][2][2];

lli dp2[32][2];

lli hownum(lli ind,lli issmall)
{

   
    if(ind==n)
    return 1;

    if(dp2[ind][issmall]!=-1)
    return dp2[ind][issmall];


    lli lo=0;
    lli hi=num[ind];


    if(issmall==1)
    {
        hi=1;

    }


    lli ans=0;

    
        for(lli i=lo;i<=hi;i++)
        {
            ans+=hownum(ind+1,issmall | (i<num[ind]));
        }

   
   
        
   
    return dp2[ind][issmall]=ans;
    

}

lli sum(lli ind,lli prevbit,lli issmall)
{

   
    if(ind==n)
    return 0;

    if(dp1[ind][issmall][prevbit]!=-1)
    return dp1[ind][issmall][prevbit];


    lli lo=0;
    lli hi=num[ind];


    if(issmall==1)
    {
        hi=1;

    }


    lli ans=0;

    if(prevbit==0)
    {
        for(lli i=lo;i<=hi;i++)
        {
            ans+=sum(ind+1,i,issmall | (i<num[ind]));
        }

    }
    else
    {
       for(lli i=lo;i<=hi;i++)
        {
            ans+=sum(ind+1,i,issmall | (i<num[ind]));
            if(i==1)
            ans+=hownum(ind+1,issmall | (i<num[ind]));
        }

    }
   
        
    return dp1[ind][issmall][prevbit]=ans;

   

}



int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;

    prepow[0]=1;

    for(lli i=1;i<32;i++)
    {
        prepow[i]=prepow[i-1]*2;
    }
    
    while (t--)
    {
        num.clear();
        memset(dp2,-1,sizeof(dp2));
        memset(dp1,-1,sizeof(dp1));
        //cin>>s;
        lli number;
        cin>>number;

        while(number>0)
        {
            num.push_back(number%2);
            number/=2;

        }
        reverse(num.begin(),num.end());
        //  for(lli i=0;i<num.size();i++)
        // {
        //    cout<<num[i]<<"\n";
        // }
       
        n=num.size();

         cout << "Case " << ff - t << ": ";

        cout<<sum(0,0,0)<<'\n';


    }
}