//		Chapter 4 Trees and Graphs Problem 3
//			List of Depths
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    queue<Node*> stak;
public:
    void populateNext(Node* root){
        if(stak.empty()) return;
        int LevelSize = stak.size();
        for(int i=0;i<LevelSize;i++){
            stak.pop();
            if(i!=LevelSize-1) root->next = stak.front();
            if(root->left) stak.push(root->left);
            if(root->right) stak.push(root->right);
            root = stak.front();
        }
        populateNext(root);
    }
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        stak.push(root);
        populateNext(root);
        return root;
    }
};
