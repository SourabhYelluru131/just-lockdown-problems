//		Chapter 4 Trees and Graphs Problem 2
//			Minimal Tree
//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/		
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
    vector<int> splice(vector<int>& nums, int start, int end){
        auto first = nums.begin()+start;
        auto last = nums.begin()+end+1;
        vector<int> vec(first,last);
        return vec;
    }
    void ArraytoBST(TreeNode* root, vector<int>& nums){
        int n = nums.size();
        vector<int> left,right;
        int middle;
        if(n%2==0) middle = n/2;
        else middle = (n-1)/2;
        root->val = nums[middle];
        left = splice(nums,0,middle-1);
        right = splice(nums,middle+1,n-1);
        if(left.size()){
            TreeNode* temp = new TreeNode();
            root->left = temp;
            ArraytoBST(temp,left);
        }
        else return;
        if(right.size()){
            TreeNode* temp = new TreeNode();
            root->right = temp;
            ArraytoBST(temp,right);
        }
        else return;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size()) return nullptr;
        TreeNode* root = new TreeNode();
        ArraytoBST(root,nums);
        return root;
    }
};
