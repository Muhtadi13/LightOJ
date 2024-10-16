#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MOD 100000007

using namespace std;
map<lli,int> valformod;

lli binExp(lli base, lli exp){
    base %= MOD;
    lli res = 1;
    while (exp > 0){
        if (exp & 1){
            res = (lli)((long long)res * base % MOD);
        }
        base = (lli)((long long)base * base % MOD);
        exp >>= 1;
    }
    return res;
}


int baby_step_giant_step(lli a,lli b,lli mod){
    lli vajok=sqrt(mod)+1;
    lli cur=1;
    lli mul=binExp(a,vajok);
    // int cnt=0;
    for(int i=0;i<=vajok;i++){
        if(valformod.count(cur)==0)
            valformod[cur]=i;
        else{
            valformod[cur]=min(valformod[cur],i);
        }
        // if(cnt++<10)
        // cout<<cur<<" "<<valformod[cur]<<"\n";
        cur*=mul;
        cur%=mod;
    }
    //baby step
    lli mn=mod+1LL;
    cur=b;
    for(int i=0;i<vajok;i++){
        if(valformod.count(cur)){
            mn=min(valformod[cur]*vajok-i,mn);
        }
        cur*=a;
        cur%=mod;
    }
    return mn;
}



int main(){
    lli t;
    cin >> t;
    lli ff;
    ff = t;
    while (t--){
        valformod.clear();

        lli k,res;
        cin>>k>>res;
        cout<<"Case "<<ff-t<<": "<<baby_step_giant_step(k,res,MOD)<<"\n";
    }
}