//  https://leetcode.com/problems/word-search-ii/
class Trie_node{
public:
    vector<Trie_node *> next;
    bool end;
    Trie_node()
    {
        next = std::vector<Trie_node *>(26,NULL);
        end = false;
    }
};

class Trie
{
public:
    Trie_node *root;
    Trie()
    {
        root = new Trie_node();
    }
    
    void insert(string &word) {
        Trie_node *node = root;
        for(char c : word)
        {
            if(node ->next[c - 'a'] == NULL) node ->next[c - 'a'] = new Trie_node();
            node = node ->next[c - 'a'];
        }
        node->end = true;
    }
    
    bool search(string &word) {
        Trie_node *node = root;
        for(char c : word)
        {
            if(node ->next[c - 'a'] == NULL) return false;
            node = node ->next[c - 'a'];
        }
        return (node->end == true); // Checks if the match is a word or prefix; if prefix, return false; else return true
    }
    
    bool startsWith(string &prefix) {
        Trie_node *node = root;
        for(char c : prefix)
        {
            if(node ->next[c - 'a'] == NULL) return false;
            node = node ->next[c - 'a'];
        }
        return true;
    }
};
class Solution {
public:
    void getposs(int i, int j, string &s, set<string> &ans, Trie *&T, vector<vector<char> > &board, vector<vector<bool> > &vis){
        if((i < 0) || (i >= board.size()) || (j < 0) || (j >= board[0].size())) return;
        if(vis[i][j]) return;
        string newS = s + board[i][j];
        if(!(T->startsWith(newS))) return;
        vis[i][j] = true;
        if(T->search(newS)) ans.insert(newS);
        getposs(i - 1, j, newS, ans, T, board, vis);
        getposs(i, j - 1, newS, ans, T, board, vis);
        getposs(i, j + 1, newS, ans, T, board, vis);
        getposs(i + 1, j, newS, ans, T, board, vis);
        vis[i][j] = false;
    }
        
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words){
        Trie *T = new Trie();
        for(string s: words) T->insert(s);
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        set<string> ans; 
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board[0].size(); j ++){ 
                string s = "";        
                getposs(i, j, s, ans, T, board, vis);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
