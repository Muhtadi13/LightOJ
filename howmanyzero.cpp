#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 103LL
#define MOD 1000000007

using namespace std;
lli dp1[MAX][MAX][2];
lli dp2[MAX][2];
vector<lli> digits(MAX);

lli n=0;
lli hownum(lli last,lli issmall)
{
    if(last==n)
    return 1;

    if(dp2[last][issmall]!=-1)
    return dp2[last][issmall];

    lli low=0;
    lli high=digits[last];

    if(issmall==1)
    {
        high=9;
    }

    lli sum=0;



    for(lli j=low;j<=high;j++)
    {
        sum+=hownum(last+1,issmall | (j<high));

    }
    return dp2[last][issmall]=sum;

}

lli howzero(lli last,lli issmall,lli start)
{
    if(last==n)
    {
        return 0;
    }

    if(dp1[last][issmall][start]!=-1)
    return dp1[last][issmall][start];

    lli low=0;
    lli high=digits[last];

    lli sum=0;

    if(issmall==1)
    {
        high=9;
    }

    for(lli j=low;j<=high;j++)
    {
       
         sum+=howzero(last+1,issmall | (j<high),start |(j>0));

         if(j==0 && start==1)
         sum+=hownum(last+1,issmall | (j<high));

    }
    return dp1[last][issmall][start]=sum;
}



// lli zero(lli last, lli issmall, lli satrtedyet)
// {
//     if (last == n)
//     {
//         return 0;
//     }
//      lli sum=0;
//     if (issmall == 1)
//     {

//         if (satrtedyet == 1)
//         {     

//             for(lli i=0;i<=digits[last];i++)
//             {
//                 if(i==0)
//                 {
//                     sum+=zero(last + 1,issmall,satrtedyet)+cnt;

//                 }
//                 else
//                 {
//                     sum+=zero(last+1,issmall,satrtedyet);
//                 }

                
//             }
//         }
//         else
//         {
//              for(lli i=0;i<=digits[last];i++)
//             {
//                 if(i==0)
//                 {
//                     sum+=zero(last + 1,issmall,satrtedyet);

//                 }
//                 else
//                 {
//                     sum+=zero(last+1,issmall,1-satrtedyet);
//                 }

                
//             }


//         }
//     }
//     else
//     {
//          if (satrtedyet == 1)
//         {     

//             for(lli i=0;i<=digits[last];i++)
//             {
//                 if(i==digits[last])
//                 {
//                     if(i==0)
//                     sum+=zero(last + 1,issmall,satrtedyet)+cnt;

//                     else
//                     sum+=zero(last+1,issmall,satrtedyet);

//                 }
//                 else
//                 {
//                     sum+=zero(last+1,1-issmall,satrtedyet);
//                 }

                
//             }
//         }
//         else
//         {
//              for(lli i=0;i<=digits[last];i++)
//             {
//                 if(i==0)
//                 {
//                     sum+=zero(last + 1,0,0);

//                 }
//                 else
//                 {
//                     if(i==digits[last])
//                     sum+=zero(last+1,0,1);

//                     else
//                     {
//                         sum+=zero(last+1,1,1);

//                     }
//                 }

                
//             }


//         }

//     }
// }

int main()
{
    lli t;
    cin >> t;
    lli ff;
    ff = t;
    while (t--)
    {
        string s1,s2;

        cin>>s1>>s2;

        n=s1.size();
        for(lli j=0;j<n;j++)
        {
            digits[j]=s1[j]-'0';
        }

        lli cnt1=0,cnt2=0;

        for(lli j=0;j<=n;j++)
        {
            for(lli i=0;i<2;i++)
            {
                dp2[j][i]=-1;
                for(lli k=0;k<2;k++)
                {
                    dp1[j][i][k]=-1;
                }
            }
        }


        if(digits[0]>0)
        {
            lli k=n;
            while(digits[k-1]==0 && k>0)
            {
                digits[k-1]=9;
                k--;
            }

            digits[k-1]-=1;
           
        }
        else
        {
             cnt2++;
        }
        cnt1=howzero(0,0,0);
        
        n=s2.size();
        for(lli j=0;j<n;j++)
        {
            digits[j]=s2[j]-'0';
        }

       for(lli j=0;j<=n;j++)
        {
            for(lli i=0;i<2;i++)
            {
                dp2[j][i]=-1;
                for(lli k=0;k<2;k++)
                {
                    dp1[j][i][k]=-1;
                }
            }
        }

        cnt2+=howzero(0,0,0);

        //cout<<cnt1<<" "<<cnt2<<"\n";
         cout<<"Case "<<ff-t<<": "<<cnt2-cnt1<<"\n";

        //cout<<cnt2-cnt1<<"\n";

        
    }
}