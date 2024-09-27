#include <bits/stdc++.h>

#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 1000000000000000000

using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    lli t;
    cin >> t;
    lli ff;
    ff = t;

    while (t--)
    {

        lli n;
        cin >> n;

       multiset<lli> fir;
        multiset<lli> sec;

        for (lli j = 0; j < n; j++)
        {
            lli x;
            cin>>x;
            fir.insert(x);
        }

        for (lli j = 0; j < n; j++)
        {
            lli x;
            cin>>x;
            sec.insert(x);
        }
        lli j = 0;

       
        lli ans = 0;
        auto it=fir.begin();

        while (it!=fir.end())
        { 
            auto l=sec.lower_bound(*it);
            if(l!=sec.begin())
            {
                l--;
                it=fir.erase(it);
                l=sec.erase(l);
                ans+=2;
                
            }
            else
            {
                it++;
            }

        } 

        cout << "Case " << ff - t << ": ";

        it=fir.begin();

        while (it!=fir.end())
        { 
            auto l=sec.find(*it);
            if(l!=sec.end())
            {
                
                it=fir.erase(it);
                l=sec.erase(l);
                ans+=1;
            }
             else
            {
                it++;
            }
        }

        cout << ans << "\n";
    }
}