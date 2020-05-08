//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    vector<int> preorder;
    int i=1;
public:
    void pot(TreeNode* root){
        if(root==nullptr) return;
        preorder.push_back(root->val);
        pot(root->left);
        pot(root->right);
    }
    void flatten(TreeNode* root) {
        pot(root);
        while(i<preorder.size()){
            root->left = nullptr;
            root->right = new TreeNode(preorder[i++]);
            root = root->right;
        }
    }
};
