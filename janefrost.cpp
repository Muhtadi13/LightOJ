#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 202
#define MOD 10000007

using namespace std;

string grid[MAX];

bool valid(plli ch, plli cor, lli n, lli m)
{
    lli fir = cor.first + ch.first;
    lli sec = cor.second + ch.second;

    if (fir >= 0 && fir < n && sec < m && sec >= 0 && grid[fir][sec] != '#')
        return true;
    return false;
}
int main()
{
    lli t;
    lli ff;
    cin >> t;
    ff = t;
    while (t--)
    {

        lli n, m;

        cin >> n >> m;
        
        for (lli i = 0; i < n; i++)
        {
            grid[i].clear();
        }

        for (lli i = 0; i < n; i++)
        {
            cin >> grid[i];
        }

        lli cnt = 0;

        vector<plli> pos;
         queue<plli> q;
         lli len[n][m];
        lli janeman[n][m];
        

        for (lli ii = 0; ii < n; ii++)
        {
            for (lli jj = 0; jj < m; jj++)
            {
                len[ii][jj] = MOD;
                janeman[ii][jj] = MOD;
            }
        }

        plli jane;

        for (lli i = 0; i < n; i++)
        {
            for (lli j = 0; j < m; j++)
            {
                if ((grid[i][j] == 'F'))
                {
                    cnt++;
                    q.push({i,j});
                    len[i][j]=0;

                }
                if ((grid[i][j] == 'J'))
                {
                    jane = {i, j};
                }
            }
        }

        plli dxy[4];
        dxy[0] = {1, 0};
        dxy[1] = {-1, 0};
        dxy[2] = {0, -1};
        dxy[3] = {0, 1};

        

        
      
           
            while (!q.empty())
            {

                plli a = q.front();
                q.pop();

                

                for (lli in = 0; in < 4; in++)
                {
                    plli ind = dxy[in];
                    lli fir = a.first + ind.first;
                    lli sec = a.second + ind.second;
                    if (valid(ind, a, n, m))
                    {
                        if (len[fir][sec] >=MOD)
                        {
                            q.push({fir, sec});
                            len[fir][sec] = len[a.first][a.second] + 1;
                        }
                    }
                }
            }
        

        // for (lli i = 0; i < cnt; i++)
        // {
        //     for (lli ii = 0; ii < n; ii++)
        //     {
        //         for (lli jj = 0; jj < m; jj++)
        //         {
        //             cout << len[ii][jj] << " ";
        //         }
        //         cout << "\n";
        //     }

        //     cout << "\n";
        // }


        queue<plli> q2;

        q2.push(jane);
        janeman[jane.first][jane.second] = 0;

        while (!q2.empty())
        {

            plli a = q2.front();
            q2.pop();

            for (lli in = 0; in < 4; in++)
            {
                plli ind = dxy[in];
                lli fir = a.first + ind.first;
                lli sec = a.second + ind.second;
                if (valid(ind, a, n, m))
                {
                    if ((len[fir][sec] > janeman[a.first][a.second] + 1) && janeman[fir][sec] >=MOD)
                    {
                        q2.push({fir, sec});
                        janeman[fir][sec] = janeman[a.first][a.second] + 1;
                    }
                }
            }
        }

        // for (lli ii = 0; ii < n; ii++)
        // {
        //     for (lli jj = 0; jj < m; jj++)
        //     {
        //         cout << janeman[ii][jj] << " ";
        //     }
        //     cout << "\n";
        // }

        lli sum = MOD;

        for (lli i = 0; i < n; i++)
        {
            sum = min(sum, janeman[i][0]);
        }

        for (lli i = 0; i < n; i++)
        {
            sum = min(sum, janeman[i][m - 1]);
        }

        for (lli i = 0; i < m; i++)
        {
            sum = min(sum, janeman[0][i]);
        }
        for (lli i = 0; i < m; i++)
        {
            sum = min(sum, janeman[n - 1][i]);
        }

        cout << "Case " << ff - t << ": ";

        if (sum >= MOD)
            cout << "IMPOSSIBLE\n";
        else
            cout << sum + 1 << "\n";
    }
}
