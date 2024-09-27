#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 505LL
#define MOD 100000007

using namespace std;

set<string> forbid;
string goal;

map<string,int> vis;

int dfs(string &s,vector<int> &mark)
{

    //cout<<s<<endl;
   


    if(forbid.find(s)!=forbid.end())
    return MOD;


    if(s==goal)
    return 0;

    
    if(vis.count(s))
    return vis[s];

    int ans=MOD;
    


    for (int i=0;i<3;i++)
    {
        string tmp;
        tmp=s;
        
        if(s[i]==goal[i])
        continue;

       

        tmp[i]='a'+(s[i]-'a'+mark[i]+26)%26;

       ans=min(ans,dfs(tmp,mark)+1);
    }

    return vis[s]=ans;
    
}

int main()
{
    lli t;
    lli ff;
    cin >> t;
    ff = t;
    while (t--)
    {
        
        forbid.clear();
        string start;


        cin>>start>>goal;
        int n;
        cin >>n;

        string tmp=start;

        

       

        for (lli j = 0; j < n; j++)
        {
            string x, y,z;
            cin >> x >> y>>z;

            for(int i=0;i<x.size();i++)
            {
                for(int j=0;j<y.size();j++)
                {
                    for(int k=0;k<z.size();k++)
                    {
                        string str;
                        str.push_back(x[i]);
                        str.push_back(y[j]);
                        str.push_back(z[k]);
                        forbid.insert(str);
                    }
                }
            }
        }

        int ans=MOD;

        for(int i=0;i<8;i++)
        {
            vector<int> mark(3);
            mark[0]=((i&(1<<2))==0)?-1:1;
            mark[1]=((i&(1<<1))==0)?-1:1;
            mark[2]=((i&(1<<0))==0)?-1:1;

            // for(int i=0;i<3;i++)
            // {
            //     cout<<mark[i]<<" ";
            // }
            // cout<<endl;
            vis.clear();

            start=tmp;

            ans=min(ans,dfs(start,mark));
        }

        cout << "Case " << ff - t << ": ";

        if (ans == MOD)
            cout << -1<<"\n";
        else
            cout << ans << "\n";
    }
}
