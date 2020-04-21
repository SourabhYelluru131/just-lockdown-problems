// CTCI Chapter 1, Problem 7
// Rotate Image
class Solution {
public:
    void rot(vector<vector<int>>& mat, int i){
        int n = mat.size();
        int j=i;
        int right = n-i-1;
        for(int k=i;k<right;k++){
            int temp = mat[k][right];
            mat[k][right]=mat[i][k];
            int temp2 = mat[right][right-k+i];
            mat[right][right-k+i] = temp;
            temp  = mat[right-k+i][i];
            mat[right-k+i][i] = temp2;
            mat[i][k] = temp;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int left = 0, right = matrix.size()-1; 
        for(int i=left;i<=right/2;i++){
            rot(matrix,i);
        }
    }
};
