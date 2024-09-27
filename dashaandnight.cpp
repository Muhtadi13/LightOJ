#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1000000009LL
#define MOD 1000000007



using namespace std;

int main()
{

    lli t=1;
    //cin >> t;
    lli ff;
    ff = t;

    while (t--)
    {
        lli n;

        cin >> n;

        vector<lli> xors(n);

        vector<lli> ors(n);

        //map<pair<lli,lli> ,lli> cnt;

        //vector<set<lli>> letterabsent(n);

        for(int i=0;i<n;i++)
        {
            string s;

            cin>>s;
            lli par=0;
            lli ispresent=0;
            for(int j=0;j<s.length();j++)
            {
                par^=(1<<(s[j]-'a'));
                ispresent|=1<<(s[j]-'a');

            }

            xors[i]=par;
            ors[i]=ispresent;

        }

        lli ref=(1<<26)-1;

        lli ans=0;

        //vector<vector<lli>> same(26);

        for(lli i=0;i<26;i++)
        {
            map<lli,lli> ereignorekoro;
            for(lli j=0;j<n;j++)
            {
                if((1<<i)&ors[j])
                continue;

                lli need=(ref^(1<<i))^xors[j];

                ans+=ereignorekoro[need];
                ereignorekoro[xors[j]]++;

                //letterabsent[i].insert(xors[j]);


            }
        }
        cout<<ans<<'\n';
        
    }

    
}