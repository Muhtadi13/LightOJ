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

        cin >> n >> k;
        string s1, s2;

        cin >> s1 >> s2;

        vector<lli> alpha1(26);
        vector<lli> alpha2(26);

        for (lli j = 0; j < n; j++)
        {
            alpha1[s1[j]-'a']++;
            alpha2[s2[j]-'a']++;
        }

        lli ans=1;
        for (lli j = 0; j < 26; j++)
        {
            if(alpha1[j]!=alpha2[j])
            {
                ans=0;
                break;
            }
        }

        for(lli j=0;j<n;j++)
        {
            if(s1[j]!=s2[j] && (j<k) &&((n-j-1)<k))
            {
                ans=0;
                break;
            }
        }
        if(ans)
        cout<<"YES\n";

        else
        cout<<"NO\n";
    }
}