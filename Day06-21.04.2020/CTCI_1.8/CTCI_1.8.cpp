//   CTCI Chapter 1, Problem 8   
//   Zero Matrix
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int> a(matrix.size());
        unordered_map<int, int> b(matrix[0].size());
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    a[i]++;
                    b[j]++;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            if(a[i]){
                for(int j=0;j<matrix[0].size();j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<matrix[0].size();j++){
            if(b[j]){
                for(int i=0;i<matrix.size();i++){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
