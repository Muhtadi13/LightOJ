#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;

lli dp[25][150];

vector<lli> num;

lli a, x;

lli gettotnums(lli ind, lli sum)
{

    //cout<<ind<<"\n";

    if (ind == a + 1)
    {
        if (sum >= x)
            return 1;

        else
            return 0;
    }

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    lli low = 1;
    lli high = 6;

    lli summer = 0;

    for (lli i = low; i <= high; i++)
    {
        summer += gettotnums(ind + 1, sum + i);
    }
    dp[ind][sum] = summer;
    return summer;
}

int main()
{
    lli t = 1;
    cin >> t;
    lli ff = t;

    lli prepower[25];
    prepower[0]=1;

    for(int i=1;i<25;i++)
    {
        prepower[i]=prepower[i-1]*6;
    }
    //cout<<prepower[24]<<"\n";

    while (t--)
    {

        cin >> a >> x;
        cout << "Case " << ff - t << ": ";

        memset(dp, -1, sizeof(dp));

        lli down = gettotnums(1, 0);

        lli g=__gcd(down,prepower[a]);

         cout << down/g ;

        if(prepower[a]/g!=1)
        cout <<"/"<<prepower[a]/g;

        cout<<'\n';
    }
}