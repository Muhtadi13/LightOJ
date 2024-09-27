#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1e6 + 6
#define MOD 1000000007LL

using namespace std;

// vector<lli> cnt(1000001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    int ff = t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<lli> v(n);
        map<lli, lli> cnt;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            cnt[v[i]]++;
        }
        sort(v.begin(), v.end());

        lli ans = 0;

        for (auto it = cnt.begin(); it != cnt.end(); it++)
        {
            lli fir = it->first;
            lli sec = it->second;
            ans += (sec * (cnt[fir] - 1) * (cnt[fir] - 2));
        }
         for (int i = 0; i < n; i++)
        {
            if(v[i]!=1 && cnt.find(1)!=cnt.end() && cnt.find(v[i]*v[i])!=cnt.end())
            ans += 1LL * cnt[1] * (cnt[v[i]*v[i]]);
        }

        lli hi = pow(v[v.size() - 1], 0.6666667);
        lli mx=v[v.size() - 1];



        for (auto it = cnt.begin(); it != cnt.end(); it++)
        {

            lli fir = it->first;
            lli sec = it->second;
            if (fir > hi)
            {
                for (lli b = 2; b * fir <= v[v.size() - 1]; b++)
                {
                    if (fir % b == 0 && cnt.find(b*fir)!=cnt.end() && cnt.find(fir/b)!=cnt.end())
                        ans += (sec * cnt[b * fir] * cnt[fir / b]);
                }
            }
            else
            {
                for (lli b = 2; b * b <= fir; b++)
                {
                    if (fir % b == 0)
                    {
                        lli ot=fir/b;
                        if (b != 1 &&cnt.find(b*fir)!=cnt.end() && cnt.find(fir/b)!=cnt.end())
                            ans += (sec * cnt[b * fir] * cnt[ot]);

                        if ((b * b) != fir && cnt.find(ot*fir)!=cnt.end() && cnt.find(b)!=cnt.end())
                            ans += (sec * cnt[fir * ot] * cnt[b]);
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    //}
}
