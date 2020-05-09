//		Chapter 4 Trees and Graphs Problem 4
//			Check Balanced
//https://leetcode.com/problems/balanced-binary-tree/
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
    int h=0;
public:
    int maxDepth(TreeNode* root)  
    {  
        if (root == NULL) return 0;  
        else
        {
            int lDepth = maxDepth(root->left);  
            int rDepth = maxDepth(root->right);  
            if (lDepth > rDepth) return(lDepth + 1);  
            else return(rDepth + 1);  
        }  
    } 
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if ((maxDepth(root->right)==maxDepth(root->left)) || abs(maxDepth(root->right)-maxDepth(root->left))==1) return (isBalanced(root->right) && isBalanced(root->left));
        return false;
    }
};
