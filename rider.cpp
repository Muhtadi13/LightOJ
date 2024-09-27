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

        lli n, m;
        cin >> n >> m;

        string riderpow[n];

        for (lli j = 0; j < n; j++)
        {
            cin >> riderpow[j];
            // cout<<riderpow[j];
        }

        map<plli, vector<plli>> adj;

        for (lli i = 0; i < n; i++)
        {
            for (lli j = 0; j < m; j++)
            {

                if (i + 1 < n && j + 2 < m)
                    adj[{i, j}].push_back({i + 1, j + 2});
                if (i + 1 < n && j - 2 >= 0)
                    adj[{i, j}].push_back({i + 1, j - 2});
                if (i + 2 < n && j + 1 < m)
                    adj[{i, j}].push_back({i + 2, j + 1});
                if (i + 2 < n && j - 1 >= 0)
                    adj[{i, j}].push_back({i + 2, j - 1});
                if (i - 1 >= 0 && j + 2 < m)
                    adj[{i, j}].push_back({i - 1, j + 2});
                if (i - 1 >= 0 && j - 2 >= 0)
                    adj[{i, j}].push_back({i - 1, j - 2});
                if (i - 2 >= 0 && j + 1 < m)
                    adj[{i, j}].push_back({i - 2, j + 1});
                if (i - 2 >= 0 && j - 1 >= 0)
                    adj[{i, j}].push_back({i - 2, j - 1});
            }
        }

        lli ans[n][m];
        for (lli i = 0; i < n; i++)
        {
            for (lli j = 0; j < m; j++)
            {
                ans[i][j] = 0;
            }
        }
        for (lli i = 0; i < n; i++)
        {
            for (lli j = 0; j < m; j++)
            {
                if (riderpow[i][j] <= '9' && riderpow[i][j] >= '1')
                {

                    // cout<<i<<j<<'\n';
                    lli p = riderpow[i][j] - '0';

                    lli len[n][m];
                    lli level[n][m];

                    for (lli ii = 0; ii < n; ii++)
                    {
                        for (lli jj = 0; jj < m; jj++)
                        {
                            len[ii][jj] = MOD;
                        }
                    }

                    queue<plli> q;

                    q.push({i, j});
                    len[i][j] = 0;
                    level[i][j] = 0;
                    lli cur = 0;

                    while (!q.empty())
                    {
                        plli a = q.front();
                        q.pop();

                        for (auto child : adj[a])
                        {
                            if (len[child.first][child.second] >= MOD)
                            {
                                // cout<<a.first<<" "<<a.second<<" ";
                                // cout<<child.first<<" "<<child.second<<" "<<add<<'\n';

                                q.push(child);
                                level[child.first][child.second] = level[a.first][a.second] + 1;
                                len[child.first][child.second] = (level[child.first][child.second]+p-1) / p;
                            }
                        }
                    }
                    //cout << "\n";

                    for (lli fir = 0; fir < n; fir++)
                    {
                        for (lli sec = 0; sec < m; sec++)
                        {
                            ans[fir][sec] += len[fir][sec];
                            //cout << len[fir][sec] << "    ";
                        }
                        //cout << "\n";
                    }
                }
            }
        }

        lli haha = MOD;

        for (lli fir = 0; fir < n; fir++)
        {
            for (lli sec = 0; sec < m; sec++)
            {
                if (ans[fir][sec] < MOD)
                    haha = min(haha, ans[fir][sec]);
            }
        }

        cout << "Case " << ff - t << ": ";

        if (haha == MOD)
            cout << -1 << "\n";
        else
            cout << haha << "\n";
    }
}
