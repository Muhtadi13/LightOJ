#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define MAX 1003
#define MOD 1000000007

using namespace std;
// string s;
// lli n;

vector<ll> grundyval(MAX);
vector<pair<int,ll>> adj[MAX];
void dfs(int node,int par,ll len){

    grundyval[node]=0;
    for(auto child:adj[node]){
        if(child.first==par) continue;
        
        dfs(child.first,node,child.second);
        if(child.second==1) //1 hole normal cut korle finish
            grundyval[node]^=(1+grundyval[child.first]);
        else{
            grundyval[node]^=((grundyval[child.first]^((child.second)%2)));
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t=1;
    cin>>t;
    int ff=t;
    while(t--){

        int n;
        cin>>n;
        for(int i=0;i<=n;i++){
            adj[i].clear();
        }
        for(int i=0;i<n-1;i++){
            int x,y;ll z;
            cin>>x>>y>>z;
            adj[x].push_back({y,z});
            adj[y].push_back({x,z});
        }
        dfs(0,-1,1);
        cout<<"Case "<<ff-t<<": ";
        if(grundyval[0]){
            cout<<"Emily\n";
        }else{
            cout<<"Jolly\n";
        }
        

    }
}