#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 101LL
#define MOD 1000000007

using namespace std;
lli dp[102][102];
vector<lli> nextofit(102);

bool comp(plli f, plli s)
{
    return f.second < s.second;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    lli t;
    cin >> t;
    lli ff;
    ff = t;

    while (t--)
    {

        lli n;

        cin >> n;

        lli w;
        cin >> w ;

        vector<plli> coord(n);
        for (lli i = 0; i < n; i++)
        {
            lli x, y;
            cin >> x >> y;

            coord[i] = {x, y};
        }

        sort(coord.begin(), coord.end(), comp);
        lli j = 0;
        lli ans = 0;

        for (lli i = 0; i < n; i++)
        {
            while (j < n && coord[j].second - coord[i].second <= w)
            {
                j++;
            }
            ans++;
            i=j-1;
        }

        cout << "Case " << ff - t << ": ";

        cout << ans << "\n";
    }
}