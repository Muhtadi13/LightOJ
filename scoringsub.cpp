#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;

        vector<lli> v(n);

        for(lli i=0;i<n;i++)
        {
            cin>>v[i];
        }

        lli i=1;
        lli j=0;

        vector<lli> cost(n);

        cost[0]=1;
        lli cnt=2;

        while(i<n)
        {
            while(v[j]<cnt)
            {
                j++;
                cnt--;
            }
            cost[i]=cnt;

            i++;
            cnt++;

            
        }

        for(lli i=0;i<n;i++)
        {
            cout<<cost[i]<<" ";
        }
        cout<<"\n";

    }
}