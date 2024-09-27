#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 1000000007

using namespace std;

lli n1, n2;

lli dp[32][32];
lli cnt[32][32];

string s1, s2;

lli shortstr(lli fir, lli sec)
{

    if (fir == n1)
    {
        return dp[fir][sec] =n2 - sec;
    }

    if (sec == n2)
    {

        return dp[fir][sec] =n1 - fir;
    }

    if (dp[fir][sec] != -1)
        return dp[fir][sec];

    lli mn = MOD;
    if (s1[fir] == s2[sec])
    {
        mn = min(mn, shortstr(fir + 1, sec + 1));
    }
    else
    {
        mn = min(shortstr(fir + 1, sec), shortstr(fir, sec + 1));
    }

    /*these are fake calls as recursive dp skips some states*/
    // shortstr(fir + 1, sec);
    // shortstr(fir, sec + 1);

    mn++;
    return dp[fir][sec] = mn;
}

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;

    while (t--)
    {
        s1.clear();
        s2.clear();

        memset(dp, -1, sizeof(dp));
        // memset(cnt, 0, sizeof(cnt));

        cin >> s1 >> s2;

        n1 = s1.size();
        n2 = s2.length();
         cout << "Case " << ff - t << ": ";


        cout << shortstr(0, 0) << " ";
        for (lli i = n1; i >= 0; i--)
        {
            cnt[i][n2] = 1;
        }
        for (lli i = n2; i >= 0; i--)
        {
            cnt[n1][i] = 1;
        }
        // cnt[n1][n2]=0;

        for (lli i = n1 - 1; i >= 0; i--)
        {
            for (lli j = n2 - 1; j >= 0; j--)
            {

                if (s1[i] == s2[j])
                {
                    cnt[i][j] = cnt[i + 1][j + 1];
                }
                else
                {
                    
                    if (dp[i][j + 1] == dp[i + 1][j])
                        cnt[i][j] = cnt[i][j + 1] + cnt[i + 1][j];

                    else if (dp[i][j + 1] < dp[i + 1][j])
                    {
                        cnt[i][j] = cnt[i][j + 1];
                    }
                    else
                    {
                        cnt[i][j] = cnt[i + 1][j];
                    }
                }
            }
        }
        // for(lli i=0;i<n1;i++)
        // {
        //     for(lli j=0;j<n2;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        cout << cnt[0][0] << "\n";
    }
}