#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 101LL
#define MOD 1000000007

using namespace std;
//string s;
//lli n;

vector<lli> num(MAX);

lli dp[101][101][2];

lli howmuch(lli start, lli end, lli turn)
{

    if(start>end)
    {      
        return 0;
    }

    if(dp[start][end][turn]!=-1)
    {
        return dp[start][end][turn];
    }
     lli ans = -INT_MAX;

    if (turn == 0)
    {
        lli sum = 0;
       
        for (lli i = start; i <= end; i++)
        {
            sum += num[i];

            ans = max(ans, sum - howmuch(i + 1, end, 1));
        }

        sum=0;

        for (lli i = end; i >=start; i--)
        {
            sum += num[i];

            ans = max(ans, sum - howmuch(start, i-1, 1));
        }

        //return ans;
    }
    if (turn == 1)
    {
        lli sum = 0;
        
        for (lli i = start; i <= end; i++)
        {
            sum += num[i];

            ans = max(ans, sum - howmuch(i + 1, end, 0));
        }

        sum=0;

        for (lli i = end; i >=start; i--)
        {
            sum += num[i];

            ans = max(ans, sum - howmuch(start, i-1, 0));
        }

    }
    return dp[start][end][turn]=ans;
    
}

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;

    while (t--)
    {
         memset(dp, -1, sizeof(dp));
        num.clear();
        lli n;

        cin>>n;


        for(lli i=0;i<n;i++)
        {
            cin>>num[i];
        }
         cout << "Case " << ff - t << ": ";

        cout<<howmuch(0,n-1,0)<<"\n";

    }
}