//  https://leetcode.com/problems/search-in-a-binary-search-tree/
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
    TreeNode* dfs(TreeNode* root, int val){
        if(root){
            if(root->val == val) return root;
            else{
                if(root->val > val) return dfs(root->left,val);
                else return dfs(root->right,val);
            }
        }
        else return nullptr;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = dfs(root,val);
        return res;
    }
};
