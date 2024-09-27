
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

    vector<lli> fib(50);
    fib[0]=1;
    fib[1]=2;

    for(int i=2;i<50;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }

 
    while (t--)
    {
        lli n;
        cin>>n;
        string s;


        auto lo=upper_bound(fib.begin(),fib.end(),n)-fib.begin()-1;
        // s.push_back(1);
        for(int i=lo;i>=0;i--)
        {
            if(fib[i]<=n)
            {
                s.push_back('1');
                n-=fib[i];
            }
            else
            s.push_back('0');


        }
         cout << "Case " << ff - t << ": ";


        cout<<s<<"\n";


    }
}