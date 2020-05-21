//  https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//  Not optimum, better solution exists
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
    int count,goal,ans;
public:
    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        count++;
        if(count==goal){
            ans = root->val;
            return;
        }
        inOrder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        goal = k;
        inOrder(root);
        return ans;
    }
};
