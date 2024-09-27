#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 505
#define MOD 100000007LL

using namespace std;

double dp[MAX][MAX];

double prob(lli r, lli b)
{


    if (b == 0)
    {
        return dp[r][b]=0.0;
    }
    if (b >= 1 && r == 0)
    {
        // cout<<b<<"sddfdf\n";
        return dp[r][b]=1.0;
    }

    if(dp[r][b]!=-1)
    return dp[r][b];

    //cout<<(1.0*b/(r+b))<<"\n";

    double fir = 0.0;
    double sec = 0.0;

    if (b > 1)
        fir = (1.0 * b / (r + b)) * prob(r, b - 2);

    if (b > 0 && r > 0)
    {
        sec = (1.0 * r / (r + b)) * prob(r - 1, b - 1);

        // else
        // sec=(1.0*r/(r+b));
    }
    // cout << r << b << " " << fir << " " << sec << "\n";

    return dp[r][b]=fir + sec;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli t;
    cin >> t;
    lli ff = t;
    
     for(int i=0;i<501;i++)
    {
        for(int j=0;j<501;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<501;i++)
    {
        for(int j=0;j<501;j++)
        {
            prob(i,j);

        }
    }
    
    while (t--)
    {
        lli r, b;
        cin >> r >> b;

        cout << "Case " << ff - t << ": ";

        if(b<=r)
        {
            cout<<0<<"\n";
            continue;
        }

        
        cout <<setprecision(20)<<dp[r][b] << "\n";
    }
}