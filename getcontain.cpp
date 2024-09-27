#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 101LL
#define MOD 1000000007

using namespace std;

vector<lli> v(1002);
lli n, k;

bool canitbe(lli dist)
{
    lli sum = 0;
    lli ans = 0;

    // cout<<dist<<"\n";
    for (int i = 0; i < n + 1; i++)
    {

        sum += v[i];

        if (sum > dist)
        {
            ans++;
            // cout<<sum<<"\n";
            sum = v[i];
        }
    }
    ans++;

    // cout<<"\n";

    if (ans <= k + 1)

        return true;

    return false;
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
        lli hi = 0;
        cin >> n >> k;
        lli lo = 0;

        for (lli i = 0; i < n + 1; i++)
        {
            cin >> v[i];

            hi += v[i];
            lo = max(lo, v[i]);
        }

        while (lo <= hi)
        {
            lli mid = (lo + hi) / 2;

            if (canitbe(mid))
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << "Case " << ff - t << ": ";

        cout << lo << "\n";

        vector<lli> path;

        lli sum = 0;

        for (lli i = 0; i < n + 1; i++)
        {
            sum += v[i];
            if (sum > lo)
            {
                path.push_back(sum - v[i]);

                sum = v[i];
            }
        }
        path.push_back(sum);

        if (path.size() < k + 1)
        {
            lli cnt = path.size();
            lli j = n;
            while (cnt <= k)
            {
                if (path.back() == v[j])
                {

                    path.pop_back();
                }
                else
                {

                    path.back() -= v[j];
                    cnt++;
                }
                j--;
            }

            for (; j < n; j++)
            {
                path.push_back(v[j + 1]);
            }
        }

        for (lli i = 0; i <= k; i++)
        {
            cout << path[i] << "\n";
        }
    }
}