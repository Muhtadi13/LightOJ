#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 505LL
#define MOD 1000000007LL

using namespace std;

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

        vector<plli> adj[n + 1];

        vector<lli> vis(n + 1, 0);

        for (lli j = 0; j < m; j++)
        {
            lli x, y, z;
            cin >> x >> y >> z;

            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }

        lli len[n + 1];
        lli len2[n + 1];
        for (lli i = 0; i <= n; i++)
        {
            len[i] = MOD;
            len2[i] = MOD;
        }

        cout << "Case " << ff - t << ": ";

        priority_queue<plli> q;
        q.push({0, 1});
        len[1] = 0;

        while (!q.empty())
        {
            plli po = q.top();
            q.pop();
            lli a = po.second;
            lli b = -po.first;

            // cout<<a<<" "<<po.first<<"ffgfd\n";

            if (vis[a] == 2)
            {
                continue;
            }

            vis[a]++;

            for (auto child : adj[a])
            {
                // cout<<child.first<<"dfdg ";
                // cout<<len[a] + child.second<<"\n";
                if (len[child.first] > b + child.second)
                {
                    // cout<<123<<'\n';
                    len2[child.first]=len[child.first];
                    len[child.first] = b + child.second;
                    q.push({-len[child.first], child.first});
                }

                else if (len[child.first] < b + child.second && len2[child.first] > b + child.second)
                {
                    // cout<<789<<'\n';

                    len2[child.first] = b + child.second;
                    q.push({-len2[child.first], child.first});
                }
            }
        }

        cout << len2[n] << '\n';
    }
}
