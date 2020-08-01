//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 || postorder.size()==0) return nullptr;
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        if(inorder.size()>1){
            vector<int> in,post,inr,postr;
            int i=0;
            while(inorder[i]!=root->val){
                in.push_back(inorder[i]);
                i++;
            }
            for(i=0;i<in.size();i++) post.push_back(postorder[i]); 
            root->left = buildTree(in,post);
            i=in.size()+1;
            for(;i<inorder.size();i++) inr.push_back(inorder[i]);
            i = in.size();
            for(;i<inr.size()+in.size();i++) postr.push_back(postorder[i]);
            root->right = buildTree(inr,postr);
        }
        return root;
    }
};


/*
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };*/
/**
#define tn TreeNode
class Solution {
public:**/
    /*int search(vector<int>& in,int v,int s,int e){
        for(int i=s;i<=e;i++)
            if(in[i]==v) return i;
        return -1;
    }*/
   /* tn* aa(vector<int>& in, vector<int>& post,int st,int en,unordered_map<int,int> &ha){
        if(st>en) return NULL;
        static int i=en;
        
        tn* node=new tn(post[i--]);
        if(st==en) return node;
        int ind=ha[node->val];
        //cout<<ind<<" ";
        node->right=aa(in,post,ind+1,en,ha);
        node->left=aa(in,post,st,ind-1,ha);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> ha;
        for(int i=0;i<inorder.size();i++)
            ha[inorder[i]]=i;
        return aa(inorder,postorder,0,inorder.size()-1,ha);
    }*/
/**
    int no;
    int search(vector<int>&arr,int start, int end, int val){
        
        int i=start;
        for(;i>=end;i--){
            if(arr[i]==val) break;
        }
        return i;
    }
    TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int start,int end, int pI){
        no=pI;
        if(start <end) return NULL;
        
        TreeNode* tnode = new TreeNode(postorder[no]);
        no--;
        if(start==end) return tnode;
        
        int iI=search(inorder,start,end,tnode->val);
        
        tnode->right=helper(inorder,postorder,start,iI+1,no);
        tnode->left=helper(inorder,postorder,iI-1,end,no);
        
        return tnode;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndx=postorder.size()-1;
        return helper(inorder,postorder,inorder.size()-1,0,postIndx);
    }
};**/
