//  https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> DPGrid(m+1, vector<int>(n+1));     // To create a 0 row and column to simplify code
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]!=text2[j-1]){
                    DPGrid[i][j]=max(DPGrid[i-1][j],DPGrid[i][j-1]);   //There are 2 ways to get to that place, from up or left. Choose one with the max 
                }
                else
                {
                    DPGrid[i][j]=DPGrid[i-1][j-1]+1;
                }
            }
        }
        return DPGrid[m][n];
    }
};
