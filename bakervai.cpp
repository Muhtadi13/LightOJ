#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;

lli persons[MAX][MAX];

lli dp[MAX][MAX][MAX];

lli maxhelp(lli row, lli col1, lli col2, lli mark)
{

    if (row == 0 && col1 == 0 && col2 == 1)
        return persons[row][col1] + persons[row][col2];

    if(row==0 && col1!=0)
        return -INT_MAX;

    // if (dp[row][col1][col2] != -1)
    //     return dp[row][col1][col2];
    lli sum = 0;

    if (col2 > (mark + 1))
    {
        //cout<<sum<<" fir "<<row<<col1<<col2-1<<"\n";
        sum = max(sum, maxhelp(row, col1, col2 - 1, mark)+ persons[row][col2]);
        //cout<<sum<<" firret "<<row<<col1<<col2-1<<"\n";
    }

    if (col1 > 0)
    {
        //cout<<sum<<" sec "<<row<<col1-1<<col2<<"\n";
        sum = max(sum, maxhelp(row, col1 - 1, col2, mark)+ persons[row][col1]);
        //cout<<sum<<" secret "<<row<<col1-1<<col2<<"\n";
    }

    if (row > 0)
    {
        //cout<<sum<<" third "<<row-1<<col1<<col2<<"\n";
        sum = max(sum, maxhelp(row - 1, col1, col2, col1)+ persons[row][col1]+ persons[row][col2]);
        //cout<<sum<<" thiret "<<row-1<<col1<<col2<<"\n";
    }

    //sum += persons[row][col1] ;


     cout<<sum<<" final "<<row<<col1<<col2<<"\n";

    return dp[row][col1][col2] = sum;
}

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;
    while (t--)
    {

        lli m, n;

        cin >> m >> n;

        // lli persons[m][n];

        memset(dp, -1, sizeof(dp));

        for (lli i = 0; i < m; i++)
        {
            for (lli j = 0; j < n; j++)
                cin >> persons[i][j];
        }

        // for (lli i = 0; i < m; i++)
        // {
        //     for (lli j = 0; j < n; j++)
        //     {
        //         if (j == 0)
        //         {
        //             prefsum[i][j] = persons[i][j];
        //             continue;
        //         }

        //         prefsum[i][j] = prefsum[i][j - 1] + persons[i][j];
        //     }
        // }

        cout << "Case " << ff - t << ": ";

        cout << maxhelp(m - 1, n - 2, n - 1, n - 2) << "\n";
    }
}