#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 102
lli MOD = 100000007;

using namespace std;

vector<vector<lli>> matrix_multiply(vector<vector<lli>> mat1, vector<vector<lli>> mat2, lli sz)
{
    // multiply two square matrix of same size
    vector<vector<lli>> tmp(sz, vector<lli>(sz, MOD));

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            for (int k = 0; k < sz; k++)
            {
                tmp[i][j] = min(tmp[i][j], mat1[i][k] + mat2[k][j]);
            }
        }
    }
    return tmp;
}
vector<vector<lli>> matrix_pow(vector<vector<lli>> m, lli pw, lli sz)
{
    // binary exponentiation of matrix
    if (pw == 1)
        return m;
    
    vector<vector<lli>> tmp = matrix_pow(m, pw / 2, sz);
    tmp = matrix_multiply(tmp, tmp, sz);
    if (pw % 2 == 1)
    {
        tmp = matrix_multiply(tmp, m, sz);
    }
    return tmp;
}

void matrix_path(vector<vector<lli>> mat, lli n)
{
    vector<vector<lli>> ans = matrix_pow(mat, n + 1, n);
    //vector<vector<lli>> tst = matrix_multiply(ans, mat, n);
    bool cyc = 0;

    for (int i = 0; i < n; i++)
    {
        if (ans[i][i] < 0)
        {
            cyc = 1;
            break;
        }
    }
    if (cyc == 1)
        cout << "Negative weight cycle present\n";
    
    else
    {
        cout<<"Shortest distance matrix\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ans[i][j] == MOD)
                    cout << "INF ";

                else
                    cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

void floyd_warshall(vector<vector<lli>> m, lli n)
{
    vector<vector<lli>> dp = m;

    for (lli k = 0; k < n; k++)
    {
        for (lli i = 0; i < n; i++)
        {
            for (lli j = 0; j < n; j++)
            {
                if (dp[i][k] == MOD || dp[k][j] == MOD)
                    continue;

                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    bool cyc = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i][i] < 0)
        {
            cyc = 1;
            break;
        }
    }

    if (cyc == 1)
        cout << "Negative weight cycle present\n";
    
    else
    {
        cout<<"Shortest distance matrix\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] == MOD)
                    cout << "INF ";

                else
                    cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main()
{

    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> mat(n, vector<lli>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = MOD;
        }
        mat[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        lli x, y, z;
        cin >> x >> y >> z;
        mat[x - 1][y - 1] = z;
    }
    matrix_path(mat, n);
    //floyd_warshall(mat, n);
}