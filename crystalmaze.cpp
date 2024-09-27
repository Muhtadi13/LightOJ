#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 502
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

        lli n, m, q;

        cin >> n >> m >> q;

        for (lli i = 0; i < n; i++)
        {
            grid[i].clear();
        }

        for (lli i = 0; i < n; i++)
        {
            cin >> grid[i];
        }

        lli cnt = 0;
        lli collection[n][m];
        lli len[n][m];
        vector<lli> gold(n*m);

        for (lli ii = 0; ii < n; ii++)
        {
            for (lli jj = 0; jj < m; jj++)
            {
                collection[ii][jj]=-1;
                if (grid[ii][jj] == '#')
                    len[ii][jj] = -1;

                else
                    len[ii][jj] = MOD;
            }
        }

        plli dxy[4];
        dxy[0] = {1, 0};
        dxy[1] = {-1, 0};
        dxy[2] = {0, -1};
        dxy[3] = {0, 1};

        for (lli i = 0; i < n; i++)
        {
            for (lli j = 0; j < m; j++)
            {
                if (len[i][j] == MOD)
                {


                    queue<plli> q;
                    q.push({i,j});
                    len[i][j]=0;
                    if(grid[i][j]=='C')
                    gold[cnt]++;

                    while (!q.empty())
                    {

                        plli a = q.front();
                        q.pop();

                        collection[a.first][a.second]=cnt;

                        

                        for (lli in = 0; in < 4; in++)
                        {
                            plli ind = dxy[in];
                            lli fir = a.first + ind.first;
                            lli sec = a.second + ind.second;
                            if (valid(ind, a, n, m))
                            {
                                if (len[fir][sec] == MOD)
                                {
                                    q.push({fir, sec});
                                    len[fir][sec] = len[a.first][a.second] + 1;

                                    if(grid[fir][sec]=='C')
                                    gold[cnt]++;
                                }
                                
                            }
                        }
                    }

                    cnt++;
                }
            }
        }



        // for (lli i = 0; i < cnt; i++)
        // {
        //     cout<<gold[i]<<"\n";
        // }
        //     for (lli ii = 0; ii < n; ii++)
        //     {
        //         for (lli jj = 0; jj < m; jj++)
        //         {
        //             cout << collection[ii][jj] << "      ";
        //         }
        //         cout << "\n";
        //     }

     

        cout << "Case " << ff - t << ":\n";

        for(lli i=0;i<q;i++)
        {
            lli x,y;
            cin>>x>>y;

            cout<<gold[collection[x-1][y-1]]<<"\n";
        }

        

        
    }
}
