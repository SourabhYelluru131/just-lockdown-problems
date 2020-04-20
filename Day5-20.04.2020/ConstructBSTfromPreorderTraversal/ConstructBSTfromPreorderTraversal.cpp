//          https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    int idx = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int maxim = INT_MAX) {
        if(idx==preorder.size() || preorder[idx] > maxim){
            return NULL;
        }
        int current_value = preorder[idx++];
        TreeNode *tree = new TreeNode(current_value);
        tree->left = bstFromPreorder(preorder, current_value);
        tree->right = bstFromPreorder(preorder, maxim);
        return tree;
    }
};
