#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;
vector<lli> s;
lli n;

lli dp[18][18][2][2];

lli cntpali(lli start, lli fin, lli issmall,lli backeboro)
{

    if (start > fin)
    {
        if(issmall==0 && backeboro==1)
        return 0;

        return 1;
    }
    if (dp[start][fin][issmall][backeboro] != -1)
    {

        return dp[start][fin][issmall][backeboro];
    }

    lli lo = 0;
    lli hi = s[start];

    if (issmall == 1)
        hi = 9;

    if (start == 0)
        lo = 1;

        lli sum=0;

    for(lli i=lo;i<=hi;i++)
    {
        if(i==s[fin])
        sum+=cntpali(start+1,fin-1,issmall|(i<s[start]),backeboro);

        else
        sum+=cntpali(start+1,fin-1,issmall|(i<s[start]),i>s[fin]);

    }

    return dp[start][fin][issmall][backeboro] = sum;
}

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;

    vector<lli> paliofdigit(19);

    paliofdigit[0] = 1;
    paliofdigit[1] = 9;

    for (int i = 2; i <= 18; i++)
    {
        if (i % 2 == 0)
            paliofdigit[i] = paliofdigit[i - 1];

        else
            paliofdigit[i] = paliofdigit[i - 1] * 10;
    }

    for (lli i = 1; i <= 18; i++)
    {
        paliofdigit[i] += paliofdigit[i - 1];
    }

    while (t--)
    {
         cout << "Case " << ff - t << ": ";

        s.clear();
        memset(dp, -1, sizeof(dp));

        lli a, b;

        cin >> a >> b;

        if (a > b)
            swap(a, b);
        a--;
        lli q = 1;
        lli q2 = 1;

        if(a<0)
        q--;

        if (a > 0)
        {

            while (a > 0)
            {
                s.push_back(a % 10);
                a /= 10;
            }
            reverse(s.begin(), s.end());
            n = s.size();

            q = paliofdigit[n - 1];

            q += cntpali(0, n - 1, 0,0);

            s.clear();
            memset(dp, -1, sizeof(dp));
        }
        if (b > 0)
        {

            while (b > 0)
            {
                s.push_back(b % 10);
                b /= 10;
            }
            reverse(s.begin(), s.end());
            n = s.size();

            q2 = paliofdigit[n - 1];

            q2 += cntpali(0, n - 1, 0,0);
        }

       

        cout << q2 - q << "\n";
    }
}