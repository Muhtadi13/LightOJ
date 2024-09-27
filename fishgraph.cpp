#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 505
#define MOD 10000007

using namespace std;

// vector<lli> vis(MAX + 1);
// vector<lli> mark(MAX + 1);

// bool dfs(lli node, lli par, lli curr)
// {
//     if (vis[node] == 1)
//         return false;

//     bool ans = false;

//     for (auto child : adj[node])
//     {
//         if (child != par)
//         {
//             if (child == curr)
//                 ans = true;

//             else
//                 ans |= dfs(child, node, curr);
//         }
//     }
//     return ans;
// }

int main()
{

    lli t;
    lli ff;
    cin >> t;
    ff = 0;
    while (ff<t)
    {
        ff++;
        lli n, m;
        cin >> n >> m;

        vector<int> adj[n + 1];

        for (lli j = 0; j < m; j++)
        {
            lli y, x;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int found = 0;
        int last = 0;
        int last2 = 0;
        int nnn = 0;
        vector<int> par(n + 1);
        vector<lli> len(n + 1, MOD);
        // if(ff==137)
        // {
        //     for(int i=1;i<n+1;i++)
        //     {
        //         for(lli j=0;j<adj[i].size();j++)
        //         {
        //             cout<<i<<adj[i][j];
        //         }
        //     }
        // }

        for (int j = 1; j <= n; j++)
        {

            if (adj[j].size() >= 4)
            {
                if (found == 1)
                    break;

                for (int i = 0; i <= n; i++)
                {
                    par[i] = 0;
                    len[i] = MOD;
                }

                queue<int> q;
                vector<int> route(n+1);
                len[j] = 0;
                for(auto child:adj[j])
                {
                    q.push(child);
                    len[child]=1;
                    par[child]=j;
                    route[child]=child;
                }
                
                

                while (!q.empty())
                {
                    if (found == 1)
                        break;
                    int a = q.front();
                    q.pop();

                    for (auto child : adj[a])
                    {
                        if (child != par[a])
                        {
                            if (len[child] == MOD)
                            {
                                q.push(child);
                                len[child] = len[a] + 1;
                                par[child] = a;
                                route[child]=route[a];
                            }
                            else if(route[child]!=route[a])
                            {
                                found = 1;
                                last = a;
                                last2 = child;
                                nnn = j;
                                break;
                            }
                        }
                    }
                }
            }
        }
        // if(ff==137)
        // cout<<nnn;

        if (found == 0)
        {
            cout << "NO\n";
        }

        else
        {
            cout << "yes\n";
            int child = last;
            vector<int> vis(n + 1);

            cout << len[last] + len[last2] + 3 << "\n";

            while (child != nnn)
            {
                vis[child] = 1;
                cout << child << " " << par[child] << "\n";
                child = par[child];
            }
            child = last2;
            while (child != nnn)
            {
                vis[child] = 1;
                cout << child << " " << par[child] << "\n";
                child = par[child];
            }
            cout << last << " " << last2 << "\n";
            int cnt = 0;

            for (auto child : adj[nnn])
            {
                if (cnt == 2)
                    break;
                if (vis[child] == 0)
                {
                    cout << child << " " << nnn << "\n";
                    vis[child] = 1;
                    cnt++;
                }
            }
        }
    }
}
