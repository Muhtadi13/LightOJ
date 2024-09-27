#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define ppp pair<lli, plli>
#define MAX 100005
#define MOD 1000000007
#define INF 10000000000000007

using namespace std;

const int ALPHABETSIZE = 4;

int getID(char ch){
    if(ch=='A')
    return 0;
    else if(ch=='T')
    return 1;
    else if(ch=='C')
    return 2;
    else
    return 3;
}

struct TrieNode {
    int child[ALPHABETSIZE];
    int count;
    int depth;

    TrieNode() {
        count=0;
        depth=0;
        fill(begin(child), end(child), -1);
    }
};

vector<TrieNode> trie(1);

void add_string(string &s){
    // adds new character with a full array of ALPHABETSIZE
    int index = 0;
    for (char ch : s) {
        int c = getID(ch);
         if (trie[index].child[c] == -1) {
            trie[index].child[c] = trie.size();
            trie.emplace_back();
        }
        int prev=trie[index].depth;

        index = trie[index].child[c];
        trie[index].count++;
        trie[index].depth=prev+1;
        
    }
}
// didnt check remove
void remove_string(string &s){
    //assumes that the string is already inserted in trie
    int index = 0;
    for (char ch : s) {
        int c = getID(ch);
        index = trie[index].child[c];
        trie[index].count--;
    }
    //if(trie[index].count<=0)
    //trie[index].isEndofWord = false;
}

int find_string(string &s){
    // part after || added because of remove
    // may omit if no remove operation 
    int index = 0;
    for (char ch : s) {
        int c = getID(ch);
         if (trie[index].child[c] == -1){        // || trie[trie[index].child[c]].count<=0) {
            return 0;
        }
        index = trie[index].child[c];
    }
    return trie[index].count;
}
lli dfs(int index){

    lli res=1LL*trie[index].count*trie[index].depth;

    for(int i=0;i<ALPHABETSIZE;i++){
        if(trie[index].child[i]==-1)
            continue;

        res=max(res,dfs(trie[index].child[i]));
    }
    return res;

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
        int n;
        cin>>n;

        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            add_string(s);  
        }
        lli ans=dfs(0);
        cout << "Case " << ff - t << ": ";
        cout<<ans<<"\n";
        
    }
}