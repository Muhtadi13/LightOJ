#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 101LL
#define MOD 1000000007

using namespace std;
lli dp[102][102];
vector<lli> nextofit(102);


lli line[17][17];
lli n;

bool comp(plli f,plli s)
{
    return f.second<s.second;
}

lli kaj(lli ind,lli k)
{
    if(ind==n)
    {
        return 0;
    }

    if(k==0)
    {
        return 0;
    }

    if(dp[ind][k]!=-1)
    {
        //cout<<ind<<" "<<k<<"\n";
        return dp[ind][k];
    }

    lli take=(nextofit[ind]-ind)+kaj(nextofit[ind],k-1);
    

    lli notake=kaj(ind+1,k);

    //cout<<ind<<" "<<nextofit[ind]<<" "<<k<<" "<<take<<" "<<notake<<"\n";

    return dp[ind][k]=max(take,notake);

    
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    lli t;
    cin>>t;
    lli ff;
    ff = t;

    while (t--)
    {
        memset(dp, -1, sizeof(dp));
       

        cin>>n;

        lli w,k;
        cin>>w>>k;

        vector<plli> coord(n);
        for(lli i=0;i<n;i++)
        {
            lli x,y;
            cin>>x>>y;

            coord[i]={x,y};
        } 


        sort(coord.begin(),coord.end(),comp);
        lli j=0;
        // for(lli i=0;i<n;i++)
        // {
        //     nextofit[i]=n;
           
        // }
        // for(lli i=0;i<n;i++)
        // {
           
        //     cout<<coord[i].first<<" "<<coord[i].second<<"\n";
        // } 

        for(lli i=0;i<n;i++)
        {
            while(j<n && coord[j].second-coord[i].second<=w)
            {
                j++;
            }
            nextofit[i]=j;
            // if(j==n)
            // break;
        }
        // for(lli i=0;i<n;i++)
        // {
           
        //     cout<<nextofit[i]<<" ";
        // }
        // cout<<endl;
        cout << "Case " << ff - t << ": ";

        cout<<kaj(0,k)<<"\n";

        // for(lli i=0;i<=n;i++)
        // {
        //     for(lli j=0;j<=k;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }

        //     cout<<"\n";
        // }


    }
}