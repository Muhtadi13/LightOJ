#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 101LL
#define MOD 1000000007

using namespace std;

struct matrix{
    int sz;
    vector<vector<lli>> arr;
    lli det;

    matrix(vector<vector<lli>> arr2){
        arr=arr2;
        sz=arr.size();
        det=(arr[0][0]*arr[1][1]-arr[1][0]*arr[0][1]);
    }
    matrix(int sz2){ // unit matrix 
        sz=sz2;
        arr.resize(sz,vector<lli>(sz));
        for(int i=0;i<sz;i++){
            arr[i][i]=1;

        }
        det=1;
    }
    const matrix operator *(matrix &mt){
        vector<vector<lli>> tmp(sz,vector<lli>(sz));
        for (int i = 0; i < sz; i++){
            for (int j = 0; j < sz; j++){
                tmp[i][j] = 0;
                for (int k = 0; k < sz; k++){
                    tmp[i][j] += (arr[i][k] * mt.arr[k][j])%MOD;
                    tmp[i][j] %= MOD;
                }
            }
        }
        matrix ret(tmp);
        return ret;
    }
    matrix binExp(int exp){
        matrix ans(2);
        matrix tmp=*this;
        while(exp){
            if(exp&1){
                ans=ans*tmp;
            }
            tmp=tmp*tmp;
            exp>>=1;
        }
        return ans;
    }

    matrix inverse(){
        det=(arr[0][0]*arr[1][1]-arr[1][0]*arr[0][1]);

        if(det==0){
            return *this;
        }
        matrix tmp=*this;
        swap(tmp.arr[0][0],tmp.arr[1][1]);
        tmp.arr[1][0]=-tmp.arr[1][0];
        tmp.arr[0][1]=-tmp.arr[0][1];

        return tmp;
    }
};



int main(){
    lli t;
    cin >> t;
    lli ff;
    ff = t;

    while (t--){

        int n,x,m,y,k;
        cin>>n>>x>>m>>y>>k;
        vector<vector<lli>> v={{1,1},{1,0}};
        matrix op(v);
        op=op.binExp(n-1);

        matrix op2(v);
        op2=op2.binExp(m-1);

        matrix op3(v);
        op3=op3.binExp(k-1);

        v={{(op.arr[0][0]+op.arr[1][0])%MOD,(op.arr[0][1]+op.arr[1][1])%MOD},{(op2.arr[0][0]+op2.arr[1][0])%MOD,(op2.arr[0][1]+op2.arr[1][1])%MOD}};
        matrix cur(v);
        cur=cur.inverse();
        bool tr=true;
        cout<<"Case "<<ff-t<<": ";
        if(cur.det==0){
            cout<<"Impossible\n";
            continue;
        }
        lli b0=cur.arr[0][0]*x+cur.arr[0][1]*y;
        lli a0=cur.arr[1][0]*x+cur.arr[1][1]*y;
        if(a0%cur.det!=0 || b0%cur.det!=0 || a0*cur.det<0 || b0*cur.det<0){
            cout<<"Impossible\n";
            continue;
        }
        b0/=cur.det;
        a0/=cur.det;

        lli bans=op3.arr[0][0]%MOD*b0%MOD+op3.arr[0][1]%MOD*a0%MOD;
        lli aans=op3.arr[1][0]%MOD*b0%MOD+op3.arr[1][1]%MOD*a0%MOD;
        // cout<<op3.det<<"\n";
        cout<<(bans+aans+MOD)%MOD<<"\n";
    }
}