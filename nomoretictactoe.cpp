#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 128
#define MOD 1000000007

using namespace std;
int grundyval[MAX][3][3];//0-. 1-O 2-X

int grundy(int len,short bit1,short bit2){
    if(grundyval[len][bit1][bit2]!=-1){
        return grundyval[len][bit1][bit2];
    }
    vector<int> got(MAX);
    if(bit1==1 && bit2==2 || bit1==2 && bit2==1){
        if(len<=1){
            return grundyval[len][bit1][bit2]=0;
        }
        for(int i=2;i<=len;i++){
            got[grundy(i-1,bit1,bit1)^grundy(len-i,bit1,bit2)]++;
        }
        for(int i=1;i<len;i++){
            got[grundy(i-1,bit1,bit2)^grundy(len-i,bit2,bit2)]++;
        }
    }else if(pattern==0){
        if(len<=0){
            return grundyval[len][bit1][bit2]=0;
        }
        for(int i=2;i<len;i++){
            got[grundy(i-1,0)^grundy(len-i,0)]++;
        }
        for(int i=1;i<=len;i++){
            got[grundy(i-1,1)^grundy(len-i,2)]++;
        }
        
    }else if(pattern==3){
        if(len<=0){
            return grundyval[len][bit1][bit2]=0;
        }
        for(int i=2;i<len;i++){
            got[grundy(i-1,3)^grundy(len-i,3)]++;
        }
        for(int i=1;i<=len;i++){
            got[grundy(i-1,2)^grundy(len-i,1)]++;
        }
    }else if(pattern==4){
        if(len<=0){
            return grundyval[len][bit1][bit2]=0;
        }
        for(int i=2;i<len;i++){
            got[grundy(i-1,3)^grundy(len-i,3)]++;
        }
        for(int i=1;i<=len;i++){
            got[grundy(i-1,2)^grundy(len-i,1)]++;
        }
    }

    for(int i=0;i<MAX;i++){
        if(!got[i]){
            return grundyval[len][bit1][bit2]=i;
        }
    }
    return grundyval[len][bit1][bit2]=MAX;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t=1;
    cin>>t;
    int ff=t;

    for(int i=0;i<MAX;i++){
        for(int j=0;j<4;j++){
            grundyval[i][j]=-1;
        }
    }
    for(int i=0;i<MAX;i++){
        for(int j=0;j<4;j++){
            grundy(i,j);
        }
    }
    while(t--){

        int n;
        string s;
        cin>>s;

        vector<pair<int,int>> symbols;
        for(int i=0;i<n;i++){
            if(s[i]!='.')
                symbols.push_back({i,s[i]=='O'?0:1});
        }
    }
}

