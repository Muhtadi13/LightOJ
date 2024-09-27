#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 101LL
#define MOD 1000000007

using namespace std;

vector<lli> money(MAX);

vector<double> prob(MAX);
double dp[101][10001];

double probcaught(lli ind, lli moneyleft)
{

    if (moneyleft == 0)
        return 0.0;

    if (ind < 0)
        return 1.0;

    if (dp[ind][moneyleft] != -1.0)
        return dp[ind][moneyleft];

    double notrob = probcaught(ind - 1, moneyleft);

    double rob = 1.0;

    if (moneyleft - money[ind] >= 0)
    {
        rob = probcaught(ind - 1, moneyleft - money[ind]);
        rob = rob + (1.0 - rob) * prob[ind];
    }

    return dp[ind][moneyleft] = min(rob, notrob);
}

int main()
{
    int t = 1;
    cin >> t;
    int ff = t;
    while (t--)
    {
        money.clear();
        prob.clear();
        for (lli i = 0; i < 101; i++)
        {
            for (lli j = 0; j < 10001; j++)
            {
                dp[i][j] = -1.0;
            }
        }

        lli n;
        double p;
        cin >> p >> n;

        lli sum=0;

        for (lli i = 0; i < n; i++)
        {
            cin >> money[i] >> prob[i];
            sum+=money[i];
        }

        lli ans=INT_MIN;

        for(lli i=sum;i>=0;i--)
        {
            if(probcaught(n-1,i)<=p)
            {
                ans=i;
                break;
            }

        }
         cout << "Case " << ff - t << ": ";

       cout<<ans<<"\n";
    }
}