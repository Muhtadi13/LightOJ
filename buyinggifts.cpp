#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 500005
#define MOD 1000000007

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli t;
    cin >> t;
    lli ff;
    ff = t;
    while (t--)
    {

        lli n;

        cin >> n;
        vector<plli> gifts(n);

        for (lli i = 0; i < n; i++)
        {
            lli x, y;

            cin >> x >> y;
            gifts[i] = {x, y};
        }

        // plli p1 = dif(0, 0);

        sort(gifts.begin(), gifts.end());

        //  for (lli i = 0; i < n; i++)
        // {
        //     cout<<
        //     gifts[i].first<<" "<<gifts[i].second<<"\n";
        // }

        lli mn = MOD;

        lli mx = 0;

        for (lli i = 1; i <= n - 1; i++)
        {

            mx = max(mx, gifts[i].second);
        }

        mn = min(mn, abs(gifts[0].first - mx));

        // cout<<mn<<"\n";

        for (lli i = 0; i < n - 1; i++)
        {
            mn = min(mn, abs(gifts[n - 1].first - gifts[i].second));
        }
        // cout<<mn<<"\n";

        multiset<lli> left;
        multiset<lli> right;
        for (lli i = 1; i < n; i++)
        {
            right.insert(gifts[i].second);
        }

        left.insert(gifts[0].second);

        for (lli i = 1; i < n - 1; i++)
        {
            right.erase(right.find(gifts[i].second));

            lli must = 0;

            if (!right.empty())
                must = *(right.rbegin());

            auto opt = left.upper_bound(gifts[i].first);

            if (opt != left.end())
            {

                if (*opt > must)
                    mn = min(mn, abs(gifts[i].first - *opt));
            }

            if (opt != left.begin())
                opt--;

            if (*opt > must)
                mn = min(mn, abs(gifts[i].first - *opt));

            // cout<<must<<" "<<opt<<"\n";
            left.insert(gifts[i].second);

            mn = min(mn, abs(gifts[i].first - must));
        }

        cout << mn << "\n";
    }
}