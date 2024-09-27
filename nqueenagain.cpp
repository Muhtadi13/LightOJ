
#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 505
#define MOD 100000007LL

using namespace std;

struct allqpos
{
    int x[10], y[10];
};

vector<allqpos> board;

bool valpos(lli row, lli col, allqpos &a)
{
    for (int i = 0; i < row; i++)
    {
        if (a.y[i] == col || abs(a.x[i] - row) == abs(a.y[i] - col))
            return false;
    }
    // cout<<row<<"ergfdg"<<col<<"\n";
    return true;
}

void valid_queen_gen(allqpos &a, lli row)
{
    if (row == 8)
    {
        board.push_back(a);
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        // cout<<row<<"\n";
        if (valpos(row, i, a))
        {
            a.x[row] = row;
            a.y[row] = i;
            valid_queen_gen(a, row + 1);
        }
    }
}
lli dp[10][300];

lli movecnt(int x1, int y1, int x2, int y2)
{
    if ((x1 == x2) && (y1 == y2))
        return 0;

    if ((x1 == x2) || (y1 == y2) || (abs(x1 - x2) == abs(y1 - y2)))
        return 1;
        return 2;
}

lli calc(allqpos &cur, allqpos &tar, lli mask, lli rowtar)
{

    if (rowtar == 8)
        return 0;

    if (dp[rowtar][mask] != -1)
        return dp[rowtar][mask];

    lli ans = MOD;
    for (int i = 0; i < 8; i++)
    {
        if ((mask & (1 << i)))
            continue;

        ans = min(ans, movecnt(cur.x[i], cur.y[i], tar.x[rowtar], tar.y[rowtar]) + calc(cur, tar, mask | (1 << i), rowtar + 1));
    }

    return dp[rowtar][mask] = ans;
}

int main()
{
    allqpos a;
    valid_queen_gen(a, 0);
    lli b = board.size();

    int t;
    cin >> t;
    int ff = t;

    while (t--)
    {
        allqpos cur;
        int ind = 0;
        for (int i = 0; i < 8; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < 8; j++)
            {
                if (s[j] == 'q')
                {
                    cur.x[ind] = i;
                    cur.y[ind] = j;
                    ind++;
                }
            }
        }

        // for (int j = 0; j < 8; j++)
        //     cout << cur.x[j] << " " << cur.y[j] << "\n";

        // cout<<"\n";

        lli ans = MOD;

        for (int i = 0; i < b; i++)
        {
            memset(dp, -1, sizeof(dp));
            //cout<<calc(cur, board[i], 0, 0)<<"\n";
            ans = min(ans, calc(cur, board[i], 0, 0));
        }
        cout << "Case " << ff - t << ": ";

        cout << ans << "\n";

        // for(lli mask=1;mask<(1<<8);mask++)
        // {

        // }
    }
}