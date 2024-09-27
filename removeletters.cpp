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
    lli ff;
    ff = t;
    while (t--)
    {
        lli n, k;

        cin >> n ;
        string s1;

        cin >> s1;
        lli ans=n-1;

        for(lli j=2;j<n;j++)
        {
            if(s1[j]==s1[j-2])
            ans--;
        }
        cout<<ans<<"\n";
    }
}
