#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 30004LL
#define MOD 10056
using namespace std;

vector<plli> adj[MAX];
lli mx = 0;
lli mxnode = 1;

vector<lli> distdown(MAX);
vector<lli> maxlen(MAX);
vector<lli> maxlen2(MAX);

lli dfs(lli node, lli par)
{

    lli mx = 0;
    lli mx2 = 0;

    for (auto child : adj[node])
    {
        if (child.first != par)
        {
            lli ch = dfs(child.first, node) + child.second;

            if (ch > mx)
            {
                mx2 = mx;
                mx = ch;
            }
            else if (ch > mx2)
            {
                mx2 = ch;
            }
        }
    }

    maxlen2[node] = mx2;
    return maxlen[node] = mx;
}
void dfs2(plli node, plli par)
{
    if (par.first != -1)
    {

        if (maxlen[par.first] == maxlen[node.first] + node.second)
        {
            if (maxlen2[par.first] + node.second > maxlen[node.first])
            {
                maxlen2[node.first] = maxlen[node.first];
                maxlen[node.first] = maxlen2[par.first] + node.second;
            }
            else if (maxlen2[par.first] + node.second > maxlen2[node.first])
            {
                maxlen2[node.first] = maxlen2[par.first] + node.second;
            }
        }

        else
        {
            // maxlen[node.first] = max(maxlen1[par.first] + node.second, maxlen[node.first]);
            if (maxlen[par.first] + node.second > maxlen[node.first])
            {
                maxlen2[node.first] = maxlen[node.first];
                maxlen[node.first] = maxlen[par.first] + node.second;
            }
            else if (maxlen[par.first] + node.second > maxlen2[node.first])
            {
                maxlen2[node.first] = maxlen[par.first] + node.second;
            }
        }
    }

    for (auto child : adj[node.first])
    {

        if(child.first!=par.first)
        dfs2(child, node);
    }
}

int main()
{
    lli t;
    cin >> t;
    lli ff = t;

    while (t--)
    {
        lli n;
        cin >> n;
        for (lli j = 0; j < n; j++)
        {
            adj[j].clear();
            maxlen2[j] = 0;
            maxlen[j] = 0;
        }

        mx = 0;
        mxnode = 0;

        for (lli j = 0; j < n - 1; j++)
        {
            lli s, f, w;

            cin >> s >> f >> w;

            adj[s].push_back({f, w});
            adj[f].push_back({s, w});
        }

        dfs(0, -1);

        // for (lli j = 0; j < n; j++)
        // {
        //     cout << maxlen[j] << " " << maxlen2[j] << "\n";
        // }

        dfs2({0, 0}, {-1, -1});

        cout << "Case " << ff - t << ":\n";

        for (lli j = 0; j < n; j++)
        {
            cout << maxlen[j] << "\n";
        }
    }
}