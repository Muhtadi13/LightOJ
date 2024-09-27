#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;

lli dp[10][83][83][2];

vector<lli> num;

lli a, b, k;

lli gettotnums(lli ind, lli modwhole, lli moddigit, lli issmall)
{

    // cout<<ind<<" "<<issmall<<"\n";

    if (ind == num.size())
    {
        if (modwhole == 0 && moddigit == 0)
            return 1;

        else
            return 0;
    }

    if (dp[ind][modwhole][moddigit][issmall] != -1)
        return dp[ind][modwhole][moddigit][issmall];

    lli low = 0;
    lli high = num[ind];

    if (issmall == 1)
    {
        high = 9;
    }

    lli sum = 0;

    for (lli i = 0; i <= high; i++)
    {
        sum += gettotnums(ind + 1, (modwhole * 10 + i) % k, (moddigit + i) % k, issmall | (i < num[ind]));
    }
     dp[ind][modwhole][moddigit][issmall] = sum;
     return sum;
}

int main()
{
    lli t = 1;
    cin >> t;
    lli ff = t;

    while (t--)
    {

        cin >> a >> b >> k;
        cout << "Case " << ff - t << ": ";

        if (k >= 82)
            cout << 0 << '\n';

        else
        {
            
            memset(dp, -1, sizeof(dp));
            a--;

            while (b > 0)
            {
                num.push_back(b % 10);
                b /= 10;
            }

            reverse(num.begin(), num.end());

            // for (lli j = 0; j < num.size(); j++)
            //     cout<<num[j]<<" ";
            lli up = gettotnums(0, 0, 0, 0);

            num.clear();
            memset(dp, -1, sizeof(dp));

            lli down = 0;


            while (a > 0)
            {
                num.push_back(a % 10);
                a /= 10;
            }
            reverse(num.begin(), num.end());

                //         for (lli j = 0; j < num.size(); j++)
                // cout<<num[j]<<" ";
            

            down = gettotnums(0, 0, 0, 0);
            
            
            cout << up - down << '\n';
            num.clear();
        }
    }
}