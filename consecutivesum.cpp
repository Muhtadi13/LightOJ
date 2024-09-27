#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define ppp pair<lli, plli>
#define MAX 100005
#define MOD 1000000007
#define INF 10000000000000007

using namespace std;

const int ALPHABETSIZE = 2;


struct TrieNode {
    int child[ALPHABETSIZE];
   lli value;
    TrieNode() {
        value=0;
        fill(begin(child), end(child), -1LL);
    }
};

vector<TrieNode> trie(1);

void add_xor(lli n){
    // adds new character with a full array of ALPHABETSIZE
    int index = 0;
    for (int i=31;i>=0;i--) {
        bool bit=(n&(1LL<<i));
         if (trie[index].child[bit] == -1LL) {
            trie[index].child[bit] = trie.size();
            trie.emplace_back();
        }
        index = trie[index].child[bit];
        
    }
    trie[index].value=n;
    //cout<<trie[index].value<<"\n";
    
}

lli find_pref(lli n){ 
    int index = 0;
    for (int i=31;i>=0;i--) {
        bool c=(n&(1LL<<i));
         if (trie[index].child[!c] != -1LL){
            index = trie[index].child[!c];        
        }
         else if (trie[index].child[c] != -1LL){
            index = trie[index].child[c];        
        }
        else{
            return trie[index].value;
        }
    }
    return trie[index].value;
}
int find_mnpref(lli n){ 
    int index = 0;
    for (int i=31;i>=0;i--) {
        bool c=(n&(1LL<<i));
        //cout<<c<<"\n";
         if (trie[index].child[c] != -1LL){
            index = trie[index].child[c];       
        }
         else if (trie[index].child[!c] != -1LL){
            index = trie[index].child[!c];       
        }
        else{
            return trie[index].value;
        }
    }
    return trie[index].value;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    int ff=t;
    while(t--){
        trie.clear();
        trie.emplace_back();
        //cout<<trie.size()<<"dfsdf\n";
        // trie[0].count=0;
        // memset(trie[0].child,-1,sizeof(trie[0].child));
        int n;
        cin>>n;
        lli prefxor=0;
        //add_xor(prefxor);
        lli ans=0;
        lli ans2=MOD;

        for(int i=0;i<n;i++){
            add_xor(prefxor);
           lli x;
           cin>>x;
           
           prefxor^=x;
           
           ans=max(ans,prefxor^find_pref(prefxor));
           ans2=min(ans2,prefxor^find_mnpref(prefxor));
           
           
           //cout<<ans<<" "<<ans2<<"\n";   
        }
        
      cout << "Case " << ff - t << ": ";
      cout<<ans<<" "<<ans2<<"\n";

        
    }
}