//    https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/530/week-3/3300/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        int right = 1;
        for (int i = 1; i < nums.size(); i++)
            ans[i] = ans[i - 1] * nums[i - 1];
        for (int i = nums.size() - 1; i >= 0; i--)      // Filling result from right with right product as a variable and left profuct already in the array
        {
            ans[i] = ans[i] * right;
            right = right * nums[i];
        }
        return ans;
    }
};
