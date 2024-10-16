#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 350
#define MOD 1000000007

using namespace std;
// string s;
// lli n;
string s;
int n;
vector<int> grundyval(MAX);
int grundy(int len){
    if(grundyval[len]!=-1){
        return grundyval[len];
    }

    if(len<=4){
        return grundyval[len]=0;
    }
    set<int> st;
    for(int i=2;2*i<len;i++){
        st.insert(grundy(i)^grundy(len-i-1));
    }
    int cur=0;
    for(auto el=st.begin();el!=st.end();el++){
        if(*el!=cur){
            return grundyval[len]=cur;
        }
        cur++;
    }
    return grundyval[len]=cur;
}

int main(){
    int t=1;
    cin>>t;
    int ff=t;
    for(int i=0;i<MAX;i++){
        grundyval[i]=-1;
    }
    for(int i=0;i<MAX;i++){
        grundyval[i]=grundy(i);
    }
    while (t--){
        
        cin>>s;
        s="X.."+s+"..X";
        n=s.size();

        // cout<<s<<"\n";
        vector<int> onecnt;
        for(int i=3;i<n-3;i++){
            if(s[i]=='X')
                continue;
            
            if(s[i-1]=='X' && s[i+1]=='X' || s[i-1]=='X' && s[i-2]=='X' || s[i+1]=='X' && s[i+2]=='X'){
                // cout<<i<<"\n";
                onecnt.push_back(i-2);
            }
        }

        int cnt=0;
        int xo=0;
        for(int i=1;i<n;i++){
            if(s[i]=='X'){
                if(cnt<=4){
                    cnt=0;
                    continue;
                }
                xo^=grundyval[cnt];
                cnt=0;
                continue;
            }
            cnt++;
        }
        cout<<"Case "<<ff-t<<": ";
        if(xo==0 && (int)onecnt.size()==0){
            cout<<"0\n";
        }else if(onecnt.size()>0){
            for(int i=0;i<(int)onecnt.size();i++){
                cout<<onecnt[i]<<" ";
            }
            cout<<"\n";

        }else{
            for(int i=3;i<n-3;i++){
                if(s[i]=='X' || s[i-1]=='X' || s[i-2]=='X' || s[i+1]=='X' || s[i+2]=='X')
                    continue;
                
                int left=i;
                int right=i;
                while(s[left]=='.'){
                    left--;
                }
                while(s[right]=='.'){
                    right++;
                }
                int now=right-left-1;
                // cout<<i-2<<" "<<now<<"\n";
                now=xo^grundyval[now];
                left=i-left-1;
                right=right-i-1;
                if((now^grundyval[left]^grundyval[right])==0){
                    onecnt.push_back(i-2);
                }
                
            }
            sort(onecnt.begin(),onecnt.end());
            for(int i=0;i<(int)onecnt.size();i++){
                cout<<onecnt[i]<<" ";
            }
            cout<<"\n";
        }
    }
}