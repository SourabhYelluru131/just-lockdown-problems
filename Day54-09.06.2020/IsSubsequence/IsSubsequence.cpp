//  https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()>t.length()) return false;
        vector<vector<bool>> dp(s.length()+1,vector<bool>(t.length()+1));
        for(int i=1;i<dp.size();i++) dp[i][0]=false;
        for(int i=0;i<dp[0].size();i++) dp[0][i]=true;
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(i>j){
                    dp[i][j]=false;
                }
                else{
                    if(s.at(i-1)==t.at(j-1)) dp[i][j]=dp[i-1][j-1];
                    else dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};
