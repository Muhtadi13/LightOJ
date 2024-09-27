#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 505LL
#define MOD 1000000007

using namespace std;

vector<lli> vis(MAX);
vector<lli> len(MAX, MOD);
vector<lli> adj[MAX];
lli ans = MOD;

int dfs(lli par, lli node, lli ind)
{
    // cout<<len[node]<<" "<<node<<"fghg\n";

    if (vis[node] != 0)
    {
        ans = min(ans, ind - len[node]);
        // cout << ans << " " << node << "hfghhg\n";

        return len[node];
    }

    vis[node] = 1;
    len[node] = ind;
    // cout << len[node] << " " << node << "\n";

    for (auto child : adj[node])
    {
        if (child != par && vis[child] != 2)
            len[node] = min(ind, dfs(node, child, ind + 1) + 1);
    }
    vis[node] = 2;
}

int main()
{
    lli t;
    lli ff;
    cin >> t;
    ff = t;
    while (t--)
    {
        lli n, m;
        cin >> n >> m;
        for (lli j = 0; j <= n; j++)
        {
            adj[j].clear();
        }

        for (lli j = 0; j < m; j++)
        {
            lli x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        ans = MOD;

        for (int i = 0; i < n; i++)
        {

            for (lli j = 0; j <= n; j++)
            {
                vis[j] = 0;
                len[j] = 0;
            }

            dfs(-1, i, 0);
        }

        cout << "Case " << ff - t << ": ";

        if (ans == MOD)
            cout << "impossible\n";
        else
            cout << ans << "\n";
    }
}