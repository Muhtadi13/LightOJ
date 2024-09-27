#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli,lli>
using namespace std;


bool inLine(plli p1,plli p2,plli p)
{
    return ((p.first-p1.first)*(p1.second-p2.second)-(p1.first-p2.first)*(p.second-p1.second))==0
}


int main()
{
    int t;
    cin>>t;
    int ff=t;
    while(t--)
    {
        lli n;
        cin>>n;
 
        vector<plli> coord(n);

        for(lli j=0;j<n;j++)
        {
            cin>>coord[j].first;
            cin>>coord[j].second;
        }


    }

    for(lli mask=1;mask<(1<<n);mask++)
    {
        for(lli i=0;)
    }
}

