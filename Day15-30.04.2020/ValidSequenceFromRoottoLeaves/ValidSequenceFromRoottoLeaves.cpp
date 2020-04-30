//
class Solution {
    vector<int> arr;
public:
    bool isValid(TreeNode* root, int index){
        if(root->val!=arr[index]) return false;  //false if it doesnt match array element
        if(index==arr.size()-1) return (!root->left && !root->right); //if last element of array, check if leaf or not. If leaf return true, else false.
        return ((root->left && isValid(root->left, index+1 )) || (root->right && isValid(root->right, index+1)));     // if not last element of array and array element matches node value , go to either left or right.
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(!root) return arr.size()==0; //if root is NULL, the array has to be of size 0, else false.
        this->arr = arr;
        return isValid(root, 0);
    }
};
