#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 505LL
#define MOD 1000000007

using namespace std;

int main()
{
    lli t;
    lli ff;
    cin >> t;
    ff = t;
    while (t--)
    {

        lli k, n, m;
        cin >> k >> n >> m;

        vector<lli> house(k);
        for (lli j = 0; j < k; j++)
        {
            cin >> house[j];
        }

        vector<lli> adj[n + 1];

        for (lli j = 0; j < m; j++)
        {

            lli x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }

        lli ans[n + 1];
        for (lli i = 0; i <= n; i++)
        {
            ans[i] = 0;
        }
        for (lli i = 0; i < k; i++)

        {

            lli len[n + 1];

            for (lli i = 0; i <= n; i++)
            {
                len[i] = MOD;
            }

            queue<lli> q;
            q.push(house[i]);

            len[house[i]] = 0;

            while (!q.empty())
            {
                lli a = q.front();
                q.pop();

                for (auto child : adj[a])
                {
                    if (len[child] == MOD)
                    {
                        q.push(child);
                        len[child] = len[a] + 1;
                    }
                }
            }

            for (lli i = 0; i <= n; i++)
            {
                ans[i] += len[i];
            }
        }

        lli haha = 0;

        for (lli fir = 0; fir <= n; fir++)
        {
            if (ans[fir] < MOD)
                haha++;
        }

        cout << "Case " << ff - t << ": ";
        cout << haha << "\n";
    }
}
