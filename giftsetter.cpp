#include <bits/stdc++.h>
#define lli long long
#define MOD 1000007
using namespace std;
const int MAX = 10000007;



int main()
{

    int t;
    cin >> t;
    int ff = t;

    while (t--)
    {
        lli k, c, n, ini;
        cin >> k >> c >> n >> ini;

        vector<lli> a(n);
        a[0] = ini;

        for (lli j = 1; j < n; j++)
        {
            a[j] = (a[j - 1] * k + c) % MOD;
        }
        sort(a.begin(),a.end());

        lli sum=0;

        for(int i=1;i<n;i++)
        {
            sum+=i*(n-i)*(a[i]-a[i-1]);
        }

          cout << "Case " << ff - t << ": ";


        
        cout << sum << "\n";
    }
}