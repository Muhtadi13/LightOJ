#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 200LL
#define MOD 1000000007

using namespace std;
string s;

lli gooddp[51][4][6];
lli baddp[51][4][6];

lli isbad(lli ind,lli vcnt,lli ccnt)
{
    

    if(ccnt==5 || vcnt==3)
    return 1;

    if(ind==s.size())
    return 0;

    if(baddp[ind][vcnt][ccnt]!=-1)
    return baddp[ind][vcnt][ccnt];

    lli ans=0;
    if(s[ind]=='?')
    {
        ans|=isbad(ind+1,vcnt+1,0);
        ans|=isbad(ind+1,0,ccnt+1);

    }

   

    else if(s[ind]=='0')
    {
        ans|=isbad(ind+1,vcnt+1,0);
    }

    else
    {
        ans|=isbad(ind+1,0,ccnt+1);
    }

    //cout<<ind<<" "<<ans<<" "<<vcnt<<" "<<ccnt<<"\n";

    return baddp[ind][vcnt][ccnt]=ans;
}

lli isgood(lli ind,lli vcnt,lli ccnt)
{
    

    if(ccnt==5 || vcnt==3)
    return 0;

    if(ind==s.size())
    return 1;

    if(gooddp[ind][vcnt][ccnt]!=-1)
    return gooddp[ind][vcnt][ccnt];


    lli ans=0;
    if(s[ind]=='?')
    {
        ans|=isgood(ind+1,vcnt+1,0);
        ans|=isgood(ind+1,0,ccnt+1);

    }

   

    else if(s[ind]=='0')
    {
        ans|=isgood(ind+1,vcnt+1,0);
    }

    else
    {
        ans|=isgood(ind+1,0,ccnt+1);
    }

    //cout<<ind<<" "<<ans<<" "<<vcnt<<" "<<ccnt<<"\n";

    return gooddp[ind][vcnt][ccnt]=ans;
}

int main()
{

    lli t;
    cin >> t;
    lli ff;
    ff = t;
    set<char> vowels;

        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');
    while (t--)
    {
        s.clear();
        memset(gooddp,-1,sizeof(gooddp));
        memset(baddp,-1,sizeof(baddp));
        

        //string s;

       

        cin>>s;
       

        for(lli i=0;i<s.size();i++)
        {
            if(s[i]=='?')
            continue;

            if(vowels.find(s[i])!=vowels.end())
            s[i]='0';

            else
            s[i]='1';


        }
         //scomp=s;

        // cout<<s<<"\n";

        //  cout<<s.size()
        // <<"\n";
        lli b=isbad(0,0,0);
        lli g=isgood(0,0,0);

         cout << "Case " << ff - t << ": ";


        if(b==1 && g==1)
        cout<<"MIXED\n";

        else if(b==1)
        cout<<"BAD\n";

        else
        cout<<"GOOD\n";

    }
}