#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 500005
#define MOD 1e18

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

        lli n,k;

        cin >> n>>k;

        vector<lli> nums(n);
    
        lli sum=0;

        for(lli i=0;i<n;i++)
        {
            cin>>nums[i];
            sum+=nums[i];  

        }
        sort(nums.begin(),nums.end());

        vector<lli> prefsum(n);
        prefsum[0]=0;

        for(lli i=1;i<n;i++)
        {
            prefsum[i]=prefsum[i-1]+nums[i];
        }

        if(sum<=k)
        {
            cout<<0<<"\n";
        }
        else if(n==1)
        {
            cout<<nums[0]-k<<"\n";
        }
        else
        {
            lli mn=MOD;

            for(lli i=n-1;i>=0;i--)
            {
                lli target=k-prefsum[i];


                lli each;
                
                if(target<0)
                each=(target-n+i+1)/(n-i);

                else
                each=target/(n-i);

                //cout<<each<<" "<<i<<"\n";

                lli huh=min(nums[0],each);

                mn=min(mn,(nums[0]-huh)+(n-i-1));
                //cout<<mn<<"hfdg\n";
            }
            cout<<mn<<"\n";
        }


        
    }
}