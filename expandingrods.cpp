#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define endl "\n"



int main()
{
    int t;
    cin >> t;
    for (int caset=0;caset<t;caset++)
    {
        double l,c;
        double temp;

        cin>>l>>temp>>c;

        double lo=l/2.0;
        double hi=1e14;

        lli cs=1000;

        double L=l*(1.0+temp*c);

        //cout<<L<<"\n";

        while(cs--)
        {
            double mid=(lo+hi)/2.0;

            double sp=2.0*mid*asin(l/(2.0*mid));

            // cout<<mid<<" "<<asin(l/(2.0*mid))<<"\n";
            // cout<<sp<<"\n";
            if(L<sp)
            {
                lo=mid;
            }
            else
            {
                hi=mid;
            }
        }
        //cout<<lo<<hi<<"\n";

        // if(temp==0 || c==0)
        //  printf("Case %d: %0.10lf\n",caset+1 ,0.0);


        // else
        printf("Case %d: %0.10lf\n",caset+1 ,lo-sqrt(lo*lo-l*l/4.0));

        

    }
}