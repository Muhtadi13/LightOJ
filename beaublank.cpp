#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 500005
#define MOD 1000000007

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli t;
    cin >> t;
    lli ff;
    ff = t;
    while (t--)
    {

        lli m,n;
        cin>>m>>n;

        lli mat[m][n];

        lli x=0;

        for(lli i=0;i<m;i+=2)
        {
             x=256*(i);
            for(lli j=0;j<n;j+=2)
            {
                mat[i][j]=x;
                if(j+1<n)
                mat[i][j+1]=x+1;

                if(i+1<m)
                mat[i+1][j]=x+2;

                if(i+1<m && j+1<n)
                 mat[i+1][j+1]=x+3;

                x+=4;

            }
           
        }
       

        cout<<m*n<<'\n';

          

        for(lli i=0;i<m;i++)
        {
            for(lli j=0;j<n;j++)
            {
                cout<<mat[i][j]<<' ';
                

            }
            cout<<'\n';
        }
    }
}