#include <bits/stdc++.h>
#define INF 1000000007LL
typedef long long lli;

using namespace std;

int main()
{
    lli t = 1;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;

        // vector<lli> v(n + 1);

        // lli q;
        // cin>>q;
        lli cur = 1;
        // vector<lli> par(n + 1, -1);
        vector<lli> value(n + 2, 0);
        value[1] = 1;

        vector<lli> mnvalue(n + 2, 0);
        mnvalue[1] = 0;

        vector<lli> mox(n + 2, 0);
        mox[1] = 1;

        vector<lli> mon(n + 2, 0);
        mon[1] = 0;

        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;

            if (c == '+')
            {
                lli nd;
                lli val;

                cin >> nd >> val;
                cur++;

                // par[cur] = nd;
                value[cur] = max(0LL, value[nd] + val);
                mox[cur] = max(mox[nd], value[cur]);

                mnvalue[cur] = min(mnvalue[nd] + val, 0LL);
                // mnvalue[cur]=min(mnvalue[cur],val);
                mon[cur] = min(mon[nd], mnvalue[cur]);
                // mon[cur]=min(mon[nd],val);
                // cout<<cur<<" "<<mox[cur]<<"\n";
            }

            else
            {
                lli u, v, k;
                cin >> u >> v >> k;

                if (mox[v] >= k && mon[v] <= k)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
        }
    }
}
