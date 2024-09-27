#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 200005LL
#define MOD 1000000007

using namespace std;

vector<lli> len(MAX);
vector<lli> adj[MAX];
lli ans = MOD;

void dfs(lli par, lli node, lli ind)
{

    len[node] = max(len[node], ind);

    for (auto child : adj[node])
    {
        if (child != par)
            dfs(node, child, ind + 1);
    }
}

int main()
{
    lli t = 1;
    lli ff;
    // cin >> t;
    ff = t;
    while (t--)
    {
        lli n;
        cin >> n;

        for (lli j = 0; j < n - 1; j++)
        {
            lli x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(-1, 1, 0);
        lli far = 0;
        lli mx = 0;
        for (lli j = 1; j <= n; j++)
        {
            if (mx < len[j])
            {
                mx = len[j];
                far = j;
            }
        }

        for (lli j = 1; j <= n; j++)
            len[j] = 0;

        dfs(-1, far, 0);
        lli far2 = 0;

        mx = 0;

        for (lli j = 1; j <= n; j++)
        {
            if (mx <= len[j])
            {
                mx = len[j];
                far2 = j;
            }
        }

        dfs(-1, far2, 0);
        sort(len.begin() + 1, len.begin() + n + 1);

        for (int k = 1; k <= n; k++)
        {
            if (mx < k)
                cout << n << " ";

            else if (mx >= 2 * k)
                cout << 1 << " ";

            else
            {
                auto x = lower_bound(len.begin() + 1, len.begin() + n + 1, k) - len.begin();
                cout << x << " ";
            }
        }
    }
}