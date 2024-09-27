#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 505LL
#define MOD 1000000007

using namespace std;

// void dfs(lli par, lli node, lli ind)
// {
//     // cout<<len[node]<<" "<<node<<"fghg\n";

//     if (vis[node] != 0)
//     {
//         ans = min(ans, ind - len[node]);
//         //cout << ans << " " << node << "hfghhg\n";
//         return;
//     }

//     vis[node] = 1;
//     len[node] = ind;
//     //cout << len[node] << " " << node << "\n";

//     for (auto child : adj[node])
//     {
//         if (child != par && vis[child]!=2)
//             dfs(node, child, ind + 1);

//         else if(vis[child]==2)
//             len[child]=min(len[child],ind);
//     }
//     vis[node]=2;
// }

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

        vector<lli> adj[n + 1];

        lli ans = MOD;

        for (lli j = 0; j < m; j++)
        {
            lli x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (lli i = 0; i < n; i++)
        {
            vector<lli> par(n + 1);
            vector<lli> len(n + 1, -1);

            queue<int> q;

            q.push(i);
            len[i] = 0;
            par[i] = -1;

            while (!q.empty())
            {
                int a = q.front();
                q.pop();

                for (auto child : adj[a])
                {
                    if (len[child] == -1)
                    {
                        q.push(child);
                        par[child] = a;
                        len[child] = len[a] + 1;
                    }

                    else if (par[a] != child)
                    {

                        ans = min(ans, len[a] + len[child] + 1);
                    }
                }
            }
        }

        cout << "Case " << ff - t << ": ";

        if (ans == MOD)
            cout << "impossible\n";
        else
            cout << ans << "\n";
    }
}
