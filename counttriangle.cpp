#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;

int main()
{
    lli t,ff;
    cin >> t;
    ff=t;

    while (t--)
    {
        lli n;
        cin >> n;

        vector<lli> side(n);

        for (lli i = 0; i < n; i++)
        {
            
            cin >> side[i];
            
        }
        lli cnt = 0;
        sort(side.begin(),side.end());
        for (lli it = 0; it<n-1; it++)
        {
           

            for (lli sec=it+1; sec<n; sec++)
            {
                lli sum = side[it] + side[sec];

               
                lli kkr=lower_bound(side.begin(),side.end(),sum)-side.begin();

                

                // if(kkr>sec)
                // cnt += (kkr-2)-sec;

                // else if(kkr>it)
                // cnt += (kkr-1)-sec;
                // else
                
                
                cnt += (kkr-sec-1);

                //cout<<side[it]<<" "<<side[sec]<<" "<<cnt<<"dfgdf\n";

            
            }
        }
         cout << "Case " << ff - t << ": ";

        cout << cnt << "\n";
    }
}