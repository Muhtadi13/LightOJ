#include <bits/stdc++.h>
#define lli long long
using namespace std;
vector<vector<lli> > mat(n,vector<lli>(n));
lli n;

lli profit(lli mask,lli row)
{
    

    lli masksec=(1<<(n-1));

    lli sum=0;

    for(lli j=0;j<n;j++)
    {

        if(mask & masksec)
        {
            masksec>>=1;
            continue;

        }
        sum=max(sum,profit(mask|masksec,row+1));
    }

}

int main()
{
    int t=1;
    cin>>t;
    int ind=t;
    while(t--)
    {
        
        cin>>n;

        

        for(lli i=0;i<n;i++)
        {
            for(lli j=0;j<n;j++)
            {
                cin>>mat[i][j];
            }
        }



    }
}