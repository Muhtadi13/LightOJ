
#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 205
#define MOD 100000007LL

using namespace std;

lli kmp(string &s)
{

    lli n = s.size();
    vector<lli> lps(n);
    lps[0] = 0;
    for (int i = 1; i < n; i++)
    {
        lli j = lps[i - 1]; // transform length to index

        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];

        if (s[i] == s[j]) // there might be a case where j hits 0 but s[i]!=s[j]
            j++;          // transform index to length

        lps[i] = j;
    }

    return lps[n - 1];
}
lli n;

string best;

lli cnt[16][16];
vector<string> v;
lli dp[16][(1LL << 15) + 1];

lli howmuch(lli i, lli mask)
{

    lli tmp = mask ^ (1LL << i);

    if (tmp == 0)
    {
        return dp[i][mask] = v[i].length();
    }
    if (dp[i][mask] != MOD)
        return dp[i][mask];

    for (lli j = 0; j < n; j++)
    {
        if ((tmp & (1LL << j)) == 0)
            continue;

        dp[i][mask] = min(dp[i][mask], howmuch(j, tmp) + cnt[j][i]);
    }
    return dp[i][mask];
}

void dfs(lli ind, lli mask, string an)
{

    lli tmp = mask ^ (1LL << ind);

    // cout<<ind<<" "<<tmp<<"\n";
    if (tmp == 0)
    {

        if (an < best)
            best = an;
        return;
    }

    for (lli j = 0; j < n; j++)
    {
        if ((tmp & (1LL << j)) == 0)
            continue;

        // cout<<j<<" "<<tmp<<" "<<dp[j][tmp]<<" "<<cnt[j][ind]<<" " <<dp[ind][mask]<<"dsfgdfg\n";

        if ((dp[j][tmp] + cnt[j][ind]) == dp[ind][mask])
        {
            // cout<<mask<<" "<<ind<<"fgfdg"<<j<<" "<<cnt[j][ind]<<"\n";
            dfs(j, tmp, v[j].substr(0, v[j].length() + cnt[j][ind] - v[ind].length()) + an);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int ff = t;

    while (t--)
    {

        cin >> n;
        vector<string> tmp(n);

        best = "Z";

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            tmp[i] = s;
            // v.push_back(s);
        }
        vector<bool> isin(n);

        for (int i = 0; i < n; i++)
        {
            if (isin[i])
                continue;

            for (int j = 0; j < n; j++)
            {
                if (j != i && tmp[i].find(tmp[j]) != string::npos)
                    isin[j] = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            // cout<<isin[i]<<"\n";
            if (!isin[i])
                v.push_back(tmp[i]);
        }

        n = v.size();

        for (int i = 0; i < n; i++)
        {
            cnt[i][i] = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                string pr = v[j] + "#" + v[i];
                lli q = kmp(pr);
                cnt[i][j] = v[j].size() - q;
            }
        }

        for (int j = 0; j <= n; j++)
        {
            for (int i = 0; i < (1LL << n); i++)
            {
                if (i == 0)
                    dp[j][i] = 0;

                else
                    dp[j][i] = MOD;
            }
        }
        lli mn = MOD;
        for (int i = 0; i < n; i++)
        {
            mn = min(mn, howmuch(i, (1LL << n) - 1));
        }

        // for (lli mask = 0; mask < ((1LL << n) - 1); mask++)
        // {
        //     for (int i = 0; i < n; i++)
        //     {

        //         if ((mask & (1LL << i)))
        //             continue;

        //         lli gui = mask | (1LL << i);
        //         if (mask == 0)
        //         {
        //             dp[i][gui] = v[i].length();
        //             continue;
        //         }

        //         for (lli j = 0; j < n; j++)
        //         {
        //             if ((mask & (1LL << j)) == 0)
        //                 continue;

        //             if ((dp[j][mask] + cnt[j][i]) < dp[i][gui])
        //             {
        //                 dp[i][gui] = dp[j][mask] + cnt[j][i];
        //             }
        //         }
        //     }
        // }

        // for (int i = 0; i < n; i++)
        // {
        //     for(lli j=0;j<(1<<n);j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }

        //     cout<<"\n";
        // }

        for (int i = 0; i < n; i++)
        {
            if (dp[i][(1LL << n) - 1] == mn)
            {
                string an = v[i];

                dfs(i, (1LL << n) - 1, an);
            }
        }

        cout << "Case " << ff - t << ": ";
        if (n > 1)
            cout << best << "\n";

        else
            cout << v[0] << "\n";
        v.clear();
    }
}