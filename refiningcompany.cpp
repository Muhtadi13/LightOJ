#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 1000000007

using namespace std;

int main()
{
    lli n;
    cin >> n;

    vector<lli> bg(8);
    map<lli, lli> is;
    map<lli, string> bolod;
    map<lli, lli> sal;
    map<lli, lli> time;
    map<lli, lli> mp;

    for (lli j = 0; j < n; j++)
    {
        lli d1, d2, d3, d4, d5, d6, timestamp, inpID;

        scanf("%lld/%lld/%lld#%lld:%lld:%lld", &d1, &d2, &d3, &d4, &d5, &d6);

        timestamp = d3;
        timestamp = timestamp * 100 + d2;
        timestamp = timestamp * 100 + d1;

        timestamp = timestamp * 100 + d4;
        timestamp = timestamp * 100 + d5;
        timestamp = timestamp * 100 + d6;

        cout<<timestamp<<"\n";
        lli year;

        scanf("%lld@seu.edu.bd", &inpID);

        scanf("%lld/%lld/%lld", &d1, &d2, &year);

        string st;

        cin >> st;

        if (is[inpID] == 1)
        {

            lli ref = time[inpID];

            if (timestamp > ref)
            {
                bolod[inpID] = st;
                sal[inpID] = year;
                time[inpID] = timestamp;
            }
        }

        else
        {
            bolod[inpID] = st;
            sal[inpID] = year;
            time[inpID] = timestamp;
            is[inpID] = 1;
        }
    }
    for (auto u : bolod)
    {

        string s4 = u.second;

        lli num = sal[u.first];

        if (s4 == "A+")
        {
            bg[0]++;
        }
        else if (s4 == "A-")
        {
            bg[1]++;
        }
        else if (s4 == "AB+")
        {
            bg[2]++;
        }
        else if (s4 == "AB-")
        {
            bg[3]++;
        }
        else if (s4 == "B+")
        {
            bg[4]++;
        }
        else if (s4 == "B-")
        {
            bg[5]++;
        }
        else if (s4 == "O+")
        {
            bg[6]++;
        }
        else if (s4 == "O-")
        {
            bg[7]++;
        }

        mp[num]++;
    }

    for (lli j = 0; j < 8; j++)
    {
        if (j == 0)
        {
            cout << "A+ ";
        }
        if (j == 1)
        {
            cout << "A- ";
        }
        if (j == 2)
        {
            cout << "AB+ ";
        }
        if (j == 3)
        {
            cout << "AB- ";
        }
        if (j == 4)
        {
            cout << "B+ ";
        }
        if (j == 5)
        {
            cout << "B- ";
        }
        if (j == 6)
        {
            cout << "O+ ";
        }
        if (j == 7)
        {
            cout << "O- ";
        }

        cout << bg[j] << "\n";
    }

    for (auto m : mp)
    {
        cout << m.first << " " << m.second << "\n";
    }
}
