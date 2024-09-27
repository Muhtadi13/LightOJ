#include <bits/stdc++.h>
#define lli long long
#define MOD 4294967296
using namespace std;
const int MAX= 1000002;
vector<int> boys(MAX);

vector<lli> adj[MAX];
lli ans;


lli dfs(lli node,lli par)
{
    lli extra=boys[node]-1;
    
    for(auto child:adj[node])
    {
        if(child!=par)
        {
            lli huh=dfs(child,node);
            extra+=huh;
            ans+=abs(huh);

        }
    }
    return extra;

}



int main()
{
   

    int t;
    cin >> t;
    int ff = t;

    while (t--)
    {
        int n;
        cin >> n;
        ans=0;

        for(lli j=0;j<n+1;j++)
        {
            adj[j].clear();
        }

        

        for(lli j=0;j<n;j++)
        {
            lli node,bois,pase;

            cin>>node>>bois>>pase;

            boys[node]=bois;

            for(lli i=0;i<pase;i++)
            {
                lli x;
                cin>>x;

                adj[node].push_back(x);
                adj[x].push_back(node);
            }

        }

        dfs(1,0);


        cout << "Case " << ff - t << ": ";

        cout<<ans<<"\n";

        
    }
}