//  https://leetcode.com/problems/perfect-squares/submissions/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i=0;i<n+1;i++){
            int mins = i;
            int y = 1 , sq = 1;
            while(sq<=i){
                mins = min(mins,1+dp[i-sq]);
                y++;
                sq = y*y;
            }
            dp[i] = mins;
        }
        return dp[n];
    }
};
