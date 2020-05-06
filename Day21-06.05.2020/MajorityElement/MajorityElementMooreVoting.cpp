//      https://leetcode.com/problems/majority-element/
//      Optimized Boyer-Moore Voting Algorithm
//      Can be solved using bit manipulation, and Boyer-Moore's Voting Algorithmclass Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    int majorityElement(vector<int>& nums) {
        int c = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (c == nums[i])
                count++;
            else
                count--;

            if (count == 0) {
                c = nums[i];
                count = 1;
            }
        }
        return c;
    }
};
