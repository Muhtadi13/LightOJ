#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;

vector<lli> nums(18);
set<lli> sums;

void calcsum(lli ind, lli sum)
{
    //cout<<"dfgds\n";
    if (ind == -1)
    {
        sums.insert(sum);
        return;
    }
    calcsum(ind - 1, sum);
    calcsum(ind - 1, sum + nums[ind]);
    calcsum(ind - 1, sum + 2 * nums[ind]);
    return;
}

int main()
{
    lli t;
    cin >> t;
    lli ff=t;

    while (t--)
    {
        lli n, k;
        cin >> n >> k;

        for (lli j = 0; j < n / 2; j++)
        {
            cin >> nums[j];
        }

        calcsum(n / 2 - 1, 0);
        cout<<"\n";

        set<lli> fir;
        fir = sums;

        sums.clear();

        for (lli j = n / 2; j < n; j++)
        {
            cin >> nums[j - n / 2];
        }

        calcsum(n - n / 2-1, 0);

        set<lli> sec;
        sec = sums;

        sums.clear();

        lli ans=0;

        for(auto nums:fir)
        {
            if(sec.find(k-nums)!=sec.end())
            {
                ans=1;
                break;
            }
        }
         cout << "Case " << ff - t << ": ";

        if(ans==0)
        {
            cout<<"No\n";
        }
        else
        cout<<"Yes\n";
    }
}