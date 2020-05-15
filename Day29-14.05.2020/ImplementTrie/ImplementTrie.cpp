//https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie {
public:
    class Trienode{
    public:
        char letter;
        bool isend;
        vector<Trienode*> children{nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                                   nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                                   nullptr,nullptr};
    };
    Trienode* root = new Trienode();
    /** Initialize your data structure here. */
    Trie() {
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trienode* current = root;
        for(auto x:word){
            int a = x-97;
            if(current->children[a]) current = current->children[a];
            else{
                Trienode* temp = new Trienode();
                temp->letter = x;
                current->children[a]= temp;
                current = temp;
            }
        }
        current->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trienode* current = root;
        //if(!root->isend) return false;
        for(int i=0;i<word.length();i++){
            int a = word.at(i)-97;
            if(current->children[a]){
                //cout << current->children[a]->letter <<endl;
                if(current->children[a]->letter==word.at(i)){
                    current = current->children[a];
                }
                else return false;
            }
            else return false;
            if(i==word.length()-1){
                if(!current->isend) return false;
                else return true;
            }
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trienode* current = root;
        //if(!root->isend) return false;
        for(int i=0;i<prefix.length();i++){
            int a = prefix.at(i)-97;
            if(current->children[a]){
                if(current->children[a]->letter==prefix.at(i)){
                    current = current->children[a];
                }
                else return false;
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
