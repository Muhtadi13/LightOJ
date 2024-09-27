#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 105LL
#define MOD 1000000007

using namespace std;

vector<lli> adj[MAX];

map<plli, lli> dir;

int dfs(lli par, lli node)
{
    lli sum = MOD;

    for (auto child : adj[node])
    {

        if (child != par)
        {
            if (child != 1)
                sum = min(sum, dfs(node, child) + dir[{node, child}]);

            else
                sum = min(sum, dir[{node, child}]);
        }
    }
    return sum;
}

int main()
{
    lli t;
    lli ff;
    cin >> t;
    ff = t;
    while (t--)
    {
        lli n;
        cin >> n;

        for (lli j = 0; j <= n; j++)
        {
            adj[j].clear();
        }

        dir.clear();

        for (lli j = 0; j < n; j++)
        {
            lli x, y, z;
            cin >> x >> y >> z;

            adj[x].push_back(y);
            adj[y].push_back(x);

            dir[{x, y}] = 0;
            dir[{y, x}] = z;
        }

        lli ans = dfs(0, 1);

        cout << "Case " << ff - t << ": ";

        cout << ans << "\n";
    }
}
