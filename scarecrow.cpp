#include <bits/stdc++.h>

#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 1000000000000000000

using namespace std;

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

        string s;
        cin >> s;

        lli ans = 0;

        lli i = 0;

        while (i < n)
        {
            if (s[i] == '.')
            {
                ans += 1;
                i += 3;
            }
            else
            {
                i++;
            }
        }
        cout << "Case " << ff - t << ": ";
        cout << ans << "\n";
    }
}