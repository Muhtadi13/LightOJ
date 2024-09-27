#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 101LL
#define MOD 1000000007

using namespace std;

vector<lli> v(100005);
lli n, k;

bool canitbe(lli strength)
{
    lli sum = 0;
    lli ans = 0;

    // cout<<dist<<"\n";
    lli prev=0;
    for (int i = 0; i < n; i++)
    {
        if(strength<0)
        return false;

        if(v[i]-prev>strength)
        return false;

        if(v[i]-prev==strength)
        strength--;

        prev=v[i];
    }

    return true;

  
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
      
        cin >> n;
        lli lo = 0;
        lli hi = 1000000001;

        for (lli i = 0; i < n ; i++)
        {
            cin >> v[i];

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

       
    }
}