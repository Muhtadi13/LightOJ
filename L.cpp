#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 505LL
#define MOD 1000000007
#define INF 10000007

using namespace std;
int main()
{
    int t = 1;
    // ifstream in("in.txt");
    //  ofstream out("out6.txt");

    while (t--)
    {
        int n, q;
        cin >> n >> q;
        double adj[2*n + 1][2*n + 1];

        for(int i=0;i<=2*n;i++)
        {
            for(int j=0;j<=2*n;j++)
            {
                adj[i][j]=INF;
            }
        }

        // vector<pair<lli, pair<lli, lli>>> ans;
        // vector<pair<lli, lli>> parent(n + 1);
        map<string, int> mp;
        int j = 1;

        for (int i = 0; i < n; i++)
        {
            string fir, sec;
            double one, two;
            cin>>one;
            cin>>fir;
            cin>>sec;
            cin>>two;
            cin>>sec;

            //scanf("%lf %s = %lf %s", one, fir, two, sec);
            if (mp[fir] == 0)
                mp[fir] = j++;

            if (mp[sec] == 0)
                mp[sec] = j++;

            //cout<<one<<" "<<fir<<" "<<two<<" "<<sec<<" "<<mp[fir]<<mp[sec]<<"\n";



            adj[mp[fir]][mp[fir]]=1;
            adj[mp[sec]][mp[sec]]=1;
            adj[mp[fir]][mp[sec]] = two;
            adj[mp[sec]][mp[fir]] = (1.0 / two);

            //cout<<"ghsdf\n";

            //cout<<adj[mp[fir]][mp[sec]]<<" "<<adj[mp[sec]][mp[fir]]<<"\n";
        }

        //  for(int i=1;i<=2*n;i++)
        // {
        //     for(int j=1;j<=2*n;j++)
        //     {
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        

        // for(auto u:mp)
        // {
        //     cout<<u.first<<" "<<u.second<<"\n";
        // }
         string fir, sec;
            double one;

        for (int i = 0; i < q; i++)
        {
           

            cin>>one;
            cin>>fir;
            cin>>sec;
            cin>>sec;


            //scanf("%lf %s to %s", one, fir, sec);

            
            int root = mp[fir];
            int dest = mp[sec];
           // cout<<root<<dest<<"\n";

            if (root == 0 || dest == 0)
            {
                cout << "impossible\n";
                continue;
            }

            vector<double> value(2*n + 1, INF);
            queue<int> pq;
            pq.push(root);
            value[root] = 1.0;
            vector<bool> processed(n + 1);

            while (!pq.empty())
            {
                int a = pq.front();
                pq.pop();

                if (processed[a])
                    continue;

                processed[a] = true;

                //cout<<a<<" "<<value[a]<<"\n";

                for (int k=1;k<=2*n;k++)
                {
                    
                    auto w=adj[a][k];
                    if(w>=INF)
                    continue;

                   
                    
                    if (processed[k])
                        continue;
                         //cout<<k<<"\n";
                    if (value[k]==INF)
                    {
                        value[k] = value[a]*w;
                        pq.push(k);
                        //parent[b] = {a, w};
                    }
                }
            }

            if(value[dest]==INF)
            cout<<"impossible\n";

            else
            cout<<setprecision(17)<<one*value[dest]<<"\n";
        }
    }
}