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

    if (fir >= 0 && fir < n && sec < m && sec >= 0 && grid[fir][sec] != '#' && grid[fir][sec] != 'm')
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

        

        vector<plli> pos;
         queue<plli> q;
         lli len[n][m];
        

        for (lli ii = 0; ii < n; ii++)
        {
            for (lli jj = 0; jj < m; jj++)
            {
                len[ii][jj] = MOD;
                
            }
        }

        plli house;

        for (lli i = 0; i < n; i++)
        {
            for (lli j = 0; j < m; j++)
            {
                if ((grid[i][j] == 'a')||(grid[i][j] == 'b')||(grid[i][j] == 'c'))
                {
                    pos.push_back({i,j});

                }

                if ((grid[i][j] == 'h'))
                {
                   house={i,j};

                }
            }
        }

        plli dxy[4];
        dxy[0] = {1, 0};
        dxy[1] = {-1, 0};
        dxy[2] = {0, -1};
        dxy[3] = {0, 1};

        

        
      
         for (lli i = 0; i < 3; i++)
        { 
            q.push(house);
            len[house.first][house.second]=0; 
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
        }

      
        

       lli sum=max(len[pos[0].first][pos[0].second],len[pos[1].first][pos[1].second]);
       sum=max(sum,len[pos[2].first][pos[2].second]);

        cout << "Case " << ff - t << ": ";

            cout << sum << "\n";
    }
}
