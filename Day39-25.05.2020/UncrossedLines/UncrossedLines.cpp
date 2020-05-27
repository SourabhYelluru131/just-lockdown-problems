//  https://leetcode.com/problems/uncrossed-lines/
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int maxim=0;
        vector<vector<int>> dp(A.size()+1, vector<int> (B.size()+1));
        for(int i=0;i<A.size()-1;i++) dp[i][0]=0;
        for(int i=0;i<B.size()-1;i++) dp[0][i]=0;
        for(int i=1;i<=A.size();i++){
            for(int j=1;j<=B.size();j++){
                if(A[i-1]==B[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                maxim = max(dp[i][j],maxim);
            }
        }
        return maxim;
    }
};
