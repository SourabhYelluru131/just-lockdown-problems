//  https://leetcode.com/problems/maximal-square/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        int maxm=0;
        vector<vector<int>> DPGrid(m+1, vector<int>(n+1));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(matrix[i-1][j-1]-48){
                    DPGrid[i][j]= min(min(DPGrid[i-1][j],DPGrid[i][j-1]),DPGrid[i-1][j-1])+1;
                    maxm = max(DPGrid[i][j],maxm);
                }
            }
        }
        int area = maxm*maxm;
        return area;
    }
};
