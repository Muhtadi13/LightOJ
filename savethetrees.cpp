#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 101LL
#define MOD 100000000000007ll

using namespace std;

//lazy propagation
//update adds new value
struct DataSet{
    lli sum;
    lli lazy;
};

const int N = 131072;//for 1e5
//const int N = 1048576 //for 1e6
DataSet segtree[N<<2];
DataSet combine(DataSet l, DataSet r){
    DataSet res;
    res.sum = min(l.sum , r.sum);
    return res;
}
DataSet makeDataSet(lli val){
    DataSet res;
    res.sum = val;
    return res;
}
void pushDown(int node, int arrleft, int arrright){
    if (segtree[node].lazy == 0)//for direct change update here
        return;
    segtree[node].sum += segtree[node].lazy;//for direct change update here
    if (arrright != arrleft){
        segtree[node<<1].lazy += segtree[node].lazy;//for direct change update here
        segtree[node<<1|1].lazy += segtree[node].lazy;//for direct change update here
    }
    segtree[node].lazy=0;//for direct change update here -1
}
void build(int node, int arrleft, int arrright){
    if (arrleft == arrright){
        segtree[node].sum=0;
        segtree[node].lazy=0;//for direct change update here -1
    }
    else{
        int arrmid = (arrleft + arrright)>>1;
        build(node<<1, arrleft, arrmid);
        build(node<<1|1, arrmid + 1, arrright);
        segtree[node] = combine(segtree[node<<1], segtree[node<<1|1]);
        segtree[node].lazy = 0;//for direct change update here -1
    }
}
void rangeUpdate(int node, int arrleft, int arrright, int posleft,int posright, lli new_val){
    pushDown(node,arrleft,arrright);
    if ((arrleft > posright) || (arrright < posleft))
        return;
    if ((posleft<=arrleft) && (posright>=arrright)){
        segtree[node].lazy += new_val;//for direct change update here
        pushDown(node,arrleft,arrright);
    }
    else{
        int arrmid = (arrleft + arrright)>>1;
        rangeUpdate(node<<1, arrleft, arrmid, posleft,posright, new_val);
        rangeUpdate(node<<1|1, arrmid + 1, arrright, posleft,posright, new_val);
        segtree[node] = combine(segtree[node<<1], segtree[node<<1|1]);
        segtree[node].lazy = 0 ;
    }
}
DataSet query(int node, int arrleft, int arrright, int L, int R){
    pushDown(node,arrleft,arrright);
    // node has a connection to arrleft or arrright not with quL or quR
    if ((L > R) || (arrleft > arrright))
        return makeDataSet(MOD);
    if ((L <= arrleft) && (R >= arrright))
        return segtree[node];
    if ((L > arrright) || (R < arrleft))
        return makeDataSet(MOD);
    int arrmid = (arrleft + arrright)>>1;
    return combine(query(node<<1, arrleft, arrmid, L, R),
                   query(node<<1|1, arrmid + 1, arrright, L, R));
}

void debug(int u, int st, int en) {
    cout<<"--->"<<u<<" "<<st<<" "<<en<<" "<<segtree[u].sum<<" "<<segtree[u].lazy<<"\n";
    if (st==en) return;
    int mid = (st+en)/2;
    debug(u<<1, st, mid);
    debug(u<<1|1, mid+1, en);
}




int main(){

    lli t;
    cin >> t;
    lli ff;
    ff = t;

    while (t--){

        int n,k;
        cin>>n;

        vector<plli> trees(n);
        vector<int> typeind(n+1);
        vector<int> leftrange(n,0);
        int left=0;
        vector<bool> isinrange(n+1);
        for(int i=0;i<n;i++){
            cin>>trees[i].first>>trees[i].second;
            while(left<i && isinrange[trees[i].first]){
                isinrange[trees[left].first]=false;
                left++;
            }
            leftrange[i]=left;
            isinrange[trees[i].first]=true;
        }
        build(1,0,n-1);
        // for(int i=0;i<n;i++){
        //     cout<<leftrange[i]<<" ";
        // }cout<<"\n";
        vector<lli> dp(n+1,MOD);
        
        //kisu jinish prev theke niye asa jay . kisu oi position ei update kora jay either satically or dynamically
        stack<int> rangemaxchangeind; //monotonically change hobe each i er jonno
        // prottek ke individual update na kore ekta range rekhe dei jetate range update kora jabe.amortized O(nlogn)
        for(int i=0;i<n;i++){
            while(!rangemaxchangeind.empty() && trees[rangemaxchangeind.top()].second<=trees[i].second){
                auto a=rangemaxchangeind.top();
                rangemaxchangeind.pop();
                int prev=0;
                if(!rangemaxchangeind.empty()){
                    prev=rangemaxchangeind.top()+1;
                }
                rangeUpdate(1,0,n-1,prev,a,-trees[a].second);
            }
            int prev=0;
            if(!rangemaxchangeind.empty()){
                prev=rangemaxchangeind.top()+1;
            }
            rangemaxchangeind.push(i);
            rangeUpdate(1,0,n-1,prev,i,trees[i].second);
            dp[i]=query(1,0,n-1,leftrange[i],i).sum;
            // cout<<i<<" "<<prev<<" "<<" "<<" "<<dp[i]<<"\n";
            rangeUpdate(1,0,n-1,i+1,i+1,dp[i]);
        }
        cout << "Case " << ff - t << ": ";
        cout<<dp[n-1]<<"\n";
        
        

    }
}