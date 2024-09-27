#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;
vector<lli> childcnt(MAX);

lli dfs(lli par,lli node,vector<lli> *tree)
{

    lli cnt=0;

    for(auto chi:tree[node])
    {
        if(chi!=par)
        {
            cnt+=dfs(node,chi,tree);

        }
    }
    childcnt[node]=cnt;
    return cnt+1;


}

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;
    while (t--)
    {
        lli n;
        cin>>n;

        vector<lli> tree[n+1];

        for(lli j=0;j<n-1;j++)
        {
            lli x,y;
            cin>>x>>y;
            tree[x].push_back(y);
            tree[y].push_back(x);

        }

        lli c=dfs(1,0,tree);

        
    }
}