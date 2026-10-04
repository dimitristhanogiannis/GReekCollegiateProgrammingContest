#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* child[26];
    bool wordEnd;

    TrieNode(){
        wordEnd = false;
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }
};

void insertKey(TrieNode* root, const string& key){
    TrieNode* curr = root;
    for(char c : key){
        if(curr->child[c-'a'] == nullptr){
            curr->child[c-'a'] = new TrieNode();
        }
        curr = curr->child[c-'a'];
    }
    curr->wordEnd = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    string s;
    
    getline(cin, s);
    cin >> m;

    TrieNode* root = new TrieNode();
    
    for(int i = 0; i < m; i++){
        string st;
        cin >> st;
        insertKey(root, st);
    }

    int n = s.length();
    int maxLen = 0;

    for(int start = 0; start < n; start++){
        vector<int> dp(n - start + 1, -1);
        dp[0] = 0;
        
        for(int i = 0; i < n - start; i++){
            if(dp[i] == -1) continue;
            
            TrieNode* curr = root;
            for(int j = i; j < n - start; j++){
                char c = s[start + j];
                if(curr->child[c-'a'] == nullptr) break;
                
                curr = curr->child[c-'a'];
                
                if(curr->wordEnd){
                    int len = j - i + 1;
                    dp[j + 1] = max(dp[j + 1], dp[i] + len);
                }
            }
        }
        
        for(int i = 0; i <= n - start; i++){
            if(dp[i] != -1){
                maxLen = max(maxLen, dp[i]);
            }
        }
    }

    cout << maxLen << endl;

    return 0;
}