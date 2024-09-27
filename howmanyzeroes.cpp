#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 1000000007

using namespace std;

int main()
{
    lli t;
    cin >> t;
    lli ff;
    ff = t;

    vector<lli> cnt(11003);

    cnt[0] = 1;

    for (lli i = 1; i < 11003; i++)
    {
        lli cc = 0;
        lli num = i;
        while (num > 0)
        {
            if (num % 10 == 0)
            {
                cc++;
            }
            num /= 10;
        }

        cnt[i] = cnt[i - 1] + cc;
    }

    while(t--)
    {
        lli m,n;
        cin>>m>>n;

        if(m==0)
        {
            cout<<cnt[n]<<"\n";
        }

        else
        {
            cout<<cnt[n]-cnt[m-1]<<"\n";
        }
    }
}