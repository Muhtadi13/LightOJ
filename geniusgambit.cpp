#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 1000000007

using namespace std;

int main()
{
    int t = 1;
    // cin >> t;
    int ff = t;
    while (t--)
    {
        lli a, b, k;

        cin >> a >> b >> k;

        lli n = a + b;

        string s1(n,'0'), s2(n,'0');

        b--;
        s2[0] = s1[0] = '1';

        if (k == 0)
        {
            for (lli i = 1; i <= b; i++)
            {
                s1[i] = s2[i] = '1';
            }
            for (lli i = b+1; i < n; i++)
            {
                s1[i] = s2[i] = '0';
            }
            cout << "YES\n";
            cout << s1 << "\n";
            cout << s2 << "\n";
        }

        else
        {

            if (a == 0 || b == 0)
            {

                cout << "NO\n";
            }
            else
            {
                s1[1] = s2[n - 1] = '1';
                s2[1] = s1[n - 1] = '0';

                for (lli i = 2; i < b + 1; i++)
                {
                    s2[i] = s1[i] = '1';
                    // s2[i]='0';
                }
                for (lli i = b + 1; i < n - 1; i++)
                {
                    s2[i] = s1[i] = '0';
                    // s2[i]='1';
                }

                if (k > n - 2)
                    cout << "NO\n";

                else
                {
                    swap(s1[k + 1], s1[n - 1]);
                    swap(s2[k + 1], s2[n - 1]);

                    cout << "YES\n";
                    cout << s1 << "\n";
                    cout << s2 << "\n";
                }
            }
        }
    }
}