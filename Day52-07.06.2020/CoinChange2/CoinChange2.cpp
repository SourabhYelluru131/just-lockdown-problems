//  https://leetcode.com/problems/coin-change-2/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1));
        for(int i=0;i<dp.size();i++) dp[i][0] = 1;
        for(int i=1;i<dp[0].size();i++) dp[0][i] = 0;
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(j<coins[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
            }
        }
        return dp[coins.size()][amount];
    }
};
