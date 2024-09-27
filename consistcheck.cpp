#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define ppp pair<lli, plli>
#define MAX 100005
#define MOD 1000000007
#define INF 10000000000000007

using namespace std;

const int ALPHABETSIZE = 10;

int getID(char ch){
    return (ch-'0');
}

struct TrieNode {
    int child[ALPHABETSIZE];
    bool isEndofWord = false;
    int count;

    TrieNode() {
        count=0;
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
        index = trie[index].child[c];
        trie[index].count++;
        
    }
    
    trie[index].isEndofWord = true;
}

void remove_string(string &s){
    //assumes that the string is already inserted in trie
    int index = 0;
    for (char ch : s) {
        int c = getID(ch);
        index = trie[index].child[c];
        trie[index].count--;
    }
    if(trie[index].count<=0)
    trie[index].isEndofWord = false;
}

int find_string(string &s){
    // part after || added because of remove
    // may omit if no remove operation 
    int index = 0;
    for (char ch : s) {
        int c = getID(ch);
        //  if (trie[index].child[c] == -1){        // || trie[trie[index].child[c]].count<=0) {
        //     return 0;
        // }
        index = trie[index].child[c];
    }
    return trie[index].count;
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
        trie[0].count=0;
        memset(trie[0].child,-1,sizeof(trie[0].child));
        int n;
        cin>>n;
        vector<string> v;

        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            add_string(s);
            v.push_back(s);            
        }

         cout << "Case " << ff - t << ": ";
         bool ans=true;
        

        for(int i=0;i<n;i++){
            int cnt=find_string(v[i]);
            if(cnt>1){
                ans=false;
                break;
            }

        }
        if(ans){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
       
      


        
    }
}