//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    list<TreeNode*> queue;
    void bfs(TreeNode* root){
        while(!queue.empty()){
            vector<int> tvec;
            for(auto x:queue){
                if(x->left) tvec.push_back(x->left->val);
                if(x->right) tvec.push_back(x->right->val);
            }
            if(!tvec.empty()) res.push_back(tvec);
            list<TreeNode*> tempq;
            for(auto x:queue){
                if(x->left) tempq.push_back(x->left);
                if(x->right) tempq.push_back(x->right);
            }
            queue = tempq;
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return res;
        vector<int> tvec;
        tvec.push_back(root->val);
        res.push_back(tvec);
        queue.push_back(root);
        bfs(root);
        reverse(res.begin() , res.end()); 
        return res;
    }
};
