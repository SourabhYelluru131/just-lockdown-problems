//  https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/
class Solution {
    int count;
public:
    void findSquares(vector<vector<int>>& matrix){
        #pragma GCC optimize ("Ofast")
        static auto _ = [] 
        { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();            // 2 magical lines to speed up code :wink:
        vector<vector<int>> dp(matrix.size()+1,vector<int> (matrix[0].size()+1));
        for(int i=0;i<dp.size();i++) dp[i][0] = 0;
        for(int i=0;i<dp[0].size();i++) dp[0][i]=0;
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(matrix[i-1][j-1]) dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                if(dp[i][j]) count+=dp[i][j];
            }
        }
    }
    int countSquares(vector<vector<int>>& matrix) {
        count = 0;
        findSquares(matrix);
        return count;
    }
};
