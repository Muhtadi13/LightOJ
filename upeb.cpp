#include <bits/stdc++.h>
#define INF 100000007LL
#define MOD 100000007LL
typedef long long lli;

const lli MAX = 100006;

using namespace std;
vector<lli> perpow;
vector<lli> catalan(MAX);
vector<bool> vis(1000005);
lli val = 0;

void calcpow()
{

    for (lli i = 2; i <= 100000LL; i++)
    {
        // cout<<"hahaha\n";
        if (vis[i])
            continue;

        vis[i] = true;

        for (lli j = i * i; j <= 10000000000LL; j = j * i)
        {
            perpow.push_back(j);
            // val++;

            if (j <= 100000)
                vis[j] = true;
        }
    }
}

void catalanCalc()
{

    catalan[0] = catalan[1] = 1;

    for (lli i = 2; i <= 20000; i++)
    {
        catalan[i] = 0;
        for (lli j = 0; j < i; j++)
        {
            catalan[i] += catalan[j] * catalan[i - j - 1];
            catalan[i]%=MOD;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    calcpow();
    sort(perpow.begin(), perpow.end());

    catalanCalc();
    catalan[0] = 0;

    lli t = 1;
    cin >> t;
    while (t--)
    {
        lli a, b;
        cin >> a >> b;

        lli val = 0;

        if (b > 3)
        {
            lli l = lower_bound(perpow.begin(), perpow.end(), a) - perpow.begin();
            lli u = upper_bound(perpow.begin(), perpow.end(), b) - perpow.begin();

            val = u - l;
        }

        cout << catalan[val] << "\n";
    }
}