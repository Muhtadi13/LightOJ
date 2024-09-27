#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;

int main()
{
    lli t;
    cin >> t;

    while (t--)
    {
        lli n,k;
        cin >> n>>k;

        lli p=0;

        for(lli i=1;i<=n;i++)
        {
            if(i*(i+1)<=2*k)
            {
                p=i;
                
            }
            else
            break;
        }

        lli x=k-(p*(p+1))/2;

        vector<lli >ans(n);

        for(lli i=0;i<p;i++)
        {
            ans[i]=i+2;
        }
        lli sum=((p+2)*(p+1)-(x+2)*(x+1))/2;

        if(p<n)
        ans[p]=-(sum+1);

        for(lli i=p+1;i<n;i++)
        {
            ans[i]=-999;
        }

        for(lli i=0;i<n;i++)
        {
            cout<<ans[i]<<" " ;
        }
        cout<<'\n';
    }
    
}