#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 505
#define MOD 100000007

using namespace std;

string grid[MAX];

bool valid(plli ch, plli cor, lli n)
{
    lli fir = cor.first + ch.first;
    lli sec = cor.second + ch.second;

   

    if (fir >= 0 && fir < n && sec < n && sec >= 0 && grid[fir][sec] == '.')
        return true;
    return false;
}

bool section(plli ch, plli cor, lli n, plli haha)
{
    lli fir = cor.first + ch.first;
    lli sec = cor.second + ch.second;

    return haha.first == fir && haha.second == sec;
}

int main()
{
    lli t;
    lli ff;
    cin >> t;
    ff = t;
    while (t--)
    {

        lli n;

        cin >> n;
        for (lli i = 0; i < n; i++)
        {
            grid[i].clear();
        }

        for (lli i = 0; i < n; i++)
        {
            cin >> grid[i];
        }

        lli cnt = 0;

        vector<plli> pos(26);
        

        for (lli i = 0; i < n; i++)
        {
            for (lli j = 0; j < n; j++)
            {
                if ((grid[i][j] >= 'A') && (grid[i][j] <= 'Z'))
                {
                    cnt++;
                    pos[grid[i][j] - 'A'] = {i, j};
                }
            }
        }

        plli dxy[4];
        dxy[0] = {1, 0};
        dxy[1] = {-1, 0};
        dxy[2] = {0, -1};
        dxy[3] = {0, 1};

    
        lli sum = 0;

        for (lli i = 0; i < cnt - 1; i++)
        {



            lli len[n][n];

            for (lli ii = 0; ii < n; ii++)
            {
                for (lli jj = 0; jj < n; jj++)
                {
                    len[ii][jj] = MOD;
                }
            }

            queue<plli> q;

            q.push(pos[i]);
            grid[pos[i].first][pos[i].second] = '.';
            len[pos[i].first][pos[i].second] = 0;

            lli mark = 0;

            while (!q.empty())
            {

                plli a = q.front();
                q.pop();

                for (lli in = 0; in < 4; in++)
                {
                    plli ind = dxy[in];
                    lli fir = a.first + ind.first;
                    lli sec = a.second + ind.second;
                    if (valid(ind, a, n))
                    {
                        if (len[fir][sec] >= MOD)
                        {
                            q.push({fir, sec});
                            len[fir][sec] = len[a.first][a.second] + 1;
                        }
                    }

                    else if (section(ind, a, n, pos[i + 1]))
                    {
                        len[fir][sec] = len[a.first][a.second] + 1;
                        sum += len[fir][sec];
                        mark = 1;
                        break;
                    }
                }

                if (mark == 1)
                    break;
            }

        }

       
        cout << "Case " << ff - t << ": ";

        if (sum >= MOD)
            cout << "Impossible\n";
        else
            cout << sum << "\n";
    }
}
