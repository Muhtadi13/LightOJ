#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 505
#define MOD 100000007

using namespace std;

int main()
{

    lli t;
    lli ff;
    cin >> t;
    ff = t;
    while (t--)
    {
        lli n,m;
        cin>>n>>m;

        lli start;
        lli finish;

        vector<lli> adj[n];

        for(lli j=0;j<m;j++)
        {
            lli y, x;
            cin>>x>>y;

            adj[x].push_back(y);
            adj[y].push_back(x);


        }

        cin >> start >> finish;

        vector<lli> len(n + 1, MOD);

        
        queue<lli> q;

        q.push(start);
        len[start] = 0;

        while (!q.empty())
        {

            lli a = q.front();
            q.pop();


            for (auto child : adj[a])
            {
                if (len[child]==MOD)

                {
                    q.push(child);
                    len[child] = len[a] + 1;
                }
            }
        }

        queue<lli> quad;
        vector<lli> len2(n + 1, MOD);

        quad.push(finish);
        len2[finish] = 0;

        while (!quad.empty())
        {

            lli a = quad.front();
            quad.pop();


            for (auto child : adj[a])
            {
                if (len2[child]==MOD)

                {
                    quad.push(child);
                    len2[child] = len2[a] + 1;
                }
            }
        }

        lli mx=0;

        for(lli j=0;j<n; j++)
        {
            //cout<<len[j]<<" "<<len2[j]<<"\n";
            mx=max(mx,len[j]+len2[j]);
        }

        cout << "Case " << ff - t << ": ";
        cout << mx << "\n";
    }
}
