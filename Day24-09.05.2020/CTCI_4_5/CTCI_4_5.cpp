//		Chapter 4 Trees and Graphs Problem 5
//			Validate Binary Search Tree
//https://leetcode.com/problems/validate-binary-search-tree/
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
    vector<int> inorder;
    int flag = 0;
public:
    void populateInorder(TreeNode* root){
        if(!root) return;
        populateInorder(root->left);
        inorder.push_back(root->val);
        populateInorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        populateInorder(root);
        int prev = inorder[0];
        for(int i=1;i<inorder.size();i++){
            if(inorder[i]<=prev) return false;
            prev = inorder[i];
        }
        return true;
    }
};
