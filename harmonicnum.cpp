#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1e6+6
#define MOD 1000000007LL

using namespace std;


vector<double> harmonic(2000006);

void precalc()
{
    double sum=0.0;
    for(int j=1;j<=100000004LL;j++)
    {
        sum=sum+(1.0/j);

        if((j%100)==0)
        {
            int ind=j/100;
            harmonic[ind]=sum;
        }

    }

}

int main()
{

    lli t;
    cin >> t;
    lli ff = t;

    precalc();
   

    

    while (t--)
    {
        int n;
        cin >> n;

        int ind=n/100;

        double ans=harmonic[ind];
        //cout<<ans<<"ghfgh\n";
        for(int j=100*ind+1;j<=n;j++)
        {
            ans=ans+(1.0/j);

        }

        cout<<setprecision(13)<<ans<<"\n";
    }
}