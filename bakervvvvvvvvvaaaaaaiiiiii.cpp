#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 100LL
#define MOD 1000000007

using namespace std;

lli dp[MAX][MAX][MAX];
lli m, n;

lli persons[MAX][MAX];

lli maxhelp(lli row1, lli col1, lli row2, lli col2)
{
    if(row1>=n || row2>=n ||col1>=m ||col2>=m )
    return -MOD;

    if (row1 == row2 && col1 == col2)
    {
        if (row1 == n - 1 && col1 == m - 1)
            return dp[row1][col1][col2] = persons[row1][col1] + persons[0][0];

        else
            return dp[row1][col1][col2] = -MOD;
    }
    if (dp[row1][col1][col2] != -1)
        return dp[row1][col1][col2];
    lli sum = 0;

    sum = max(sum, maxhelp(row1 + 1, col1, row2 + 1, col2));
    sum = max(sum, maxhelp(row1 + 1, col1, row2, col2 + 1));
    sum = max(sum, maxhelp(row1, col1 + 1, row2 + 1, col2));
    sum = max(sum, maxhelp(row1, col1 + 1, row2, col2 + 1));

    sum += persons[row1][col1] + persons[row2][col2];

    return dp[row1][col1][col2] = sum;
}

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;
    while (t--)
    {

        cin >> n >> m;

        memset(dp, -1, sizeof(dp));

        for (lli i = 0; i < n; i++)
        {
            for (lli j = 0; j < m; j++)
                cin >> persons[i][j];
        }

        cout << "Case " << ff - t << ": ";

        cout << maxhelp(1, 0, 0, 1) << "\n";
    }
}