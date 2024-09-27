#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define endl "\n"



int main()
{
    int t;
    cin >> t;
    for (int tt=0;tt<t;tt++)
    {
        int x, y;
        
        scanf("%d : %d",&x,&y);

        double sum=sqrt(x*x+y*y)*atan(1.0*y/x)+x;

        sum=(200.0*x)/sum;

        //cout<<sum<<" "<<<<"\n";

       

        printf("Case %d: %0.10lf %0.10lf\n",tt+1 , sum,1.0*y*sum/x);
    }
}