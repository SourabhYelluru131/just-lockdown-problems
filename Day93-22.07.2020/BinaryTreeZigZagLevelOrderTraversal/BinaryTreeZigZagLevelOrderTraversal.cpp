//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> sol;
        queue<TreeNode*> q;
        q.push(root);
        int levelsize = 1;
        while(!q.empty()){
            vector<int> lev;
            for(int i=0;i<levelsize;i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                lev.push_back(current->val);
            }
            sol.push_back(lev);
            levelsize = q.size();
        }
        for(int i=0;i<sol.size();i++){
            if(i%2) reverse(sol[i].begin(),sol[i].end());
        }
        return sol;
    }
};
