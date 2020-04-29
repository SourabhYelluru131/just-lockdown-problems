//    https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
#pragma GCC optimize ("Ofast")
static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();            // 2 magical lines to speed up code :wink:
class Solution {
public:
    int max_sum = INT_MIN;        //Just initializing
    int find_max_sum(TreeNode* root){
        if(!root){
            return 0;
        }
        // Post order tree traversal from here
        int l = find_max_sum(root->left);
        int r = find_max_sum(root->right);
        if(l<0) l=0;
        if(r<0) r=0;
        if (l + root->val + r >max_sum) 
            max_sum = l + root->val + r;
        
        if (l>r) return root->val + l;
        else return root->val + r;
    }
    int maxPathSum(TreeNode* root) {
        find_max_sum(root);
        return max_sum;
    }
};
