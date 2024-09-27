#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200005
#define MOD 1000000007LL

using namespace std;

int main()
{
    lli t;
    cin >> t;
    lli ff = t;

    while(t--)
    {
        lli n,m;
        cin>>n>>m;
        vector<lli> v(m);

        lli y=0;
    
        for(int i=1;i<=n;i++)
        {
            lli x;
            cin>>x;
           
            y+=x;
            v[y%m]++;
        }

        lli sum=(v[0]*(v[0]+1))/2;

        for(int i=1;i<m;i++)
        {
            if(v[i]>1)
            sum+=(v[i]*(v[i]-1))/2;
        }
        cout << "Case " << ff - t << ": ";

        cout<<sum<<"\n";
    }
}
