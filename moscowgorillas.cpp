#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1003LL
#define MOD 1000000007

using namespace std;

int main()
{
    lli t=1;
    //cin >> t;
    lli ff;
    ff = t;
    while(t--)
    {
        lli n;
        cin>>n;

        vector<lli> num1(n);
        vector<lli> indfir(n+1);
        vector<lli> num2(n);
        vector<lli> indsec(n+1);
        
        for(lli j=0;j<n;j++)
        {
            cin>>num1[j];
            indfir[num1[j]]=j+1;
            //two[j+1]=(2*two[j])%MOD;
        }

        for(lli j=0;j<n;j++)
        {
            cin>>num2[j];
            indsec[num2[j]]=j+1;
        }

        lli mn=min(indfir[1],indsec[1]);
        lli mx=max(indfir[1],indsec[1]);

        lli up=n-mx+1;

        lli sum=((mn-1)*(mn))/2+(up*(up-1))/2;
        sum+=((mx-mn)*(mx-mn-1))/2;

        //cout<<sum<<"\n";


        for(lli i=2;i<=n;i++)
        {
            lli mnt=min(indfir[i],indsec[i]);
            lli mxt=max(indfir[i],indsec[i]);

            lli down=0;

            if(mxt<mn)
            {
                up=n-mx+1;
                down=mn-mxt;
               
            }

            else if(mnt>mx)
            {
                down=mn;
                up=mnt-mx;

               
            }

            else if(mxt>mx && mnt<mn)
            {
                up=mxt-mx;
                down=mn-mnt;

                
            }
            sum+=up*down;

            mx=max(mx,mxt);
            mn=min(mn,mnt);

            //cout<<sum<<"\n";


        }

        cout<<sum+1<<"\n";


    }
}