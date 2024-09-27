#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;
string s;
lli n;

lli dp[1001][2];
lli vis[1001];
// lli dp[1001];

lli dfs(lli node, lli par, lli isnotified, vector<lli> *adj)
{
    vis[node]=1;
    if(dp[node][isnotified]!=-1)
    return dp[node][isnotified];


   
    if (isnotified == 0)
    {
        
        lli sum = 0;

        for (auto child : adj[node])
        {
            if (child == par)
                continue;

            sum+= dfs(child, node, 1, adj);
            
        }
        sum++;
        lli sum2=0;

        for (auto child : adj[node])
        {
            if (child == par)
                continue;

            sum2+= dfs(child, node, 0, adj);
            
        }

        return dp[node][isnotified]=max(sum,sum2);

    }
    else
    {
        lli sum2=0;

        for (auto child : adj[node])
        {
            if (child == par)
                continue;

            sum2+= dfs(child, node, 0, adj);
            
        }

        return dp[node][isnotified]=sum2;

    }
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
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        lli n,e;
        cin>>n>>e;
        vector<lli> adj[n+1];

        for(lli i=0;i<e;i++)
        {
            lli x,y;
            cin>>x>>y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        lli sum=0;

        for(lli i=1;i<n+1;i++)
        {
            if(vis[i]==0)
            {
                sum+=dfs(i,-1,0,adj);

            }
        }
         cout << "Case " << ff - t << ": ";

        cout<<sum<<"\n";
    }
  
}