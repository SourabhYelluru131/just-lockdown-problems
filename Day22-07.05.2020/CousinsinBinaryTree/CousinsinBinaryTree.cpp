//	https://leetcode.com/problems/cousins-in-binary-tree/
//	BFS
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
    pair<int,int> bfs(TreeNode* root, int x){
        int parent;
        int count=0;
        int begin = root->val;
        list<TreeNode*> queue;
        set<TreeNode*> visited;
        pair<int,int> ret;
        if((root->val) == x){
            ret = make_pair(0,0);
            return ret;
        }
        else{
            queue.push_back(root);
        }
        while(!queue.empty()){
            if(root->val==begin){
                count++;
                if(root->left) begin = root->left->val;
                else{
                    if(root->right) begin = root->right->val;
                    else begin = queue.front()->val;
                }
            }
            if(root->left){
                queue.push_back(root->left);
                if(root->left->val==x){
                    ret = make_pair(count,parent);
                    return ret;
                }
            }
            if(root->right){
                queue.push_back(root->right);
                if(root->right->val==x){
                    ret = make_pair(count,parent);
                    return ret;
                }
            }
            parent = root->val;
            visited.insert(root);
            root = queue.front();
            queue.pop_front();
        }
        ret = make_pair(0,0);
        return ret;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int> xp,yp;
        xp = bfs(root,x);
        yp = bfs(root,y);
        if(xp.first==yp.first && xp.second!=yp.second) return true;
        return false;
    }
};
