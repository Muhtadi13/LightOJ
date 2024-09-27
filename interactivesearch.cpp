#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define ppp pair<lli, plli>
#define MAX 100005
#define MOD 1000000007
#define INF 10000000000000007

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli t = 1;
    // cin >> t;
    lli ff = t;

    while (t--)
    {
        int low=1;
        int hi=1000000009;
        cin>>hi;
        int cnt=0;

        while(low<=hi){
            int mid=(low+hi)/2;
            cout<<"guess "<<mid<<"\n";
            cnt++;

            string res;
            cin>>res;

            if(res=="high"){
                hi=mid-1;
            }
            else if(res=="low"){
                low=mid+1;
            }
            else if(res=="correct"){
                break;
            }
            if(cnt>=30){
                cout<<"too many tries\n";
                break;
            }
        }
    }
}