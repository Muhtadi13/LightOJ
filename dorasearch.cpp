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

    while (t--)
    {

        lli n;
        cin >> n;

        vector<lli> v(n);

        for(lli j=0;j<n;j++)
        {
            cin>>v[j];
        }

        lli mn=1;
        lli mx=n;

        lli left=0;
        lli right=n-1;


        while(left<right)
        {
            if((v[left]==mn) || (v[right]==mn))
            {
                if(v[left]==mn)
                left++;

                if(v[right]==mn)
                right--;

                mn++;
            }
            else if((v[left]==mx) || (v[right]==mx))
            {
                if(v[left]==mx)
                left++;

                if(v[right]==mx)
                right--;

                mx--;
            }
            else
            break;
        }

        if(left>=right)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<left+1<<" "<<right+1<<"\n";
        }
    }
}