#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 505
#define MOD 100000007

using namespace std;

int main()
{

    vector<lli> primefacts[1001];
    for (lli i = 2; i < 1001; i++)
    {
        lli x = i;
        lli div = 2;
        while (x > 1)
        {

            if (x % div == 0)
            {

                while (x % div == 0)
                {
                    x /= div;
                }
                if(div!=i)
                primefacts[i].push_back(div);
            }
            div++;
        }
    }

    // for (lli i = 3; i < 10; i++)
    // {
    //     for(auto f:primefacts[i])
    //     {
    //         cout<<f<<" ";
    //     }
    //     cout<<"i\n";
    // }
    lli t;
    lli ff;
    cin >> t;
    ff = t;
    while (t--)
    {

        lli start;
        lli finish;

        cin >> start >> finish;

        vector<lli> len(finish + 1, MOD);

        vector<lli> vis(finish + 1, 0);

        priority_queue<lli, vector<lli>, greater<lli>> q;

        q.push(start);
        len[start] = 0;

        while (!q.empty())
        {

            lli a = q.top();
            q.pop();

            if (vis[a] == 1)
                continue;

            vis[a] = 1;

            for (auto fact : primefacts[a])
            {
                if (fact + a <= finish && len[fact + a] > len[a] + 1)

                {
                    q.push(fact + a);
                    len[fact + a] = len[a] + 1;
                }
            }
        }

        cout << "Case " << ff - t << ": ";

        if (len[finish] >= MOD)
            cout << -1 << "\n";
        else
            cout << len[finish] << "\n";
    }
}
