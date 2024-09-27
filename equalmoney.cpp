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

        vector<lli> mone(n);
        vector<lli> vis(n);
        lli sum = 0;
        for (lli j = 0; j < n; j++)
        {
            cin >> mone[j];
            sum += mone[j];
        }

        vector<lli> adj[n + 1];

        for (lli j = 0; j < m; j++)
        {

            lli x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        lli len[n + 1];
        for (lli i = 0; i <= n; i++)
        {
            len[i] = MOD;
        }

        cout << "Case " << ff - t << ": ";
        

        if (sum % n == 0)
        {
            lli ans = 1;
            lli av=sum/n;
            

            for (lli i = 1; i <= n; i++)
            {
                if (len[i] == MOD)
                {
                    lli cnt=0;
                    lli sss=0;

                    queue<lli> q;
                    q.push(i);

                    len[i] = 0;
              
                    while (!q.empty())
                    {
                        lli a = q.front();
                        q.pop();

                        sss+=mone[a-1];
                        cnt++;

                        for (auto child : adj[a])
                        {
                            if (len[child] == MOD)
                            {
                                q.push(child);
                                len[child] = len[a] + 1;
                            }
                        }
                    }

                    if(sss%cnt!=0 || sss/cnt!=av)
                    {
                        ans=0;
                        break;
                    }

                }

                


            }

            if(ans==0)
            cout<<"No\n";

            else
            cout<<"Yes\n";     
            
        }
        else
            cout << "No\n";
    }
}
