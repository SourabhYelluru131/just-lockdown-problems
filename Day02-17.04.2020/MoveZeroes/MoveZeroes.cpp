//   https://leetcode.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0;
        for(int i=0;cnt<nums.size();i++){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                if(nums[i]==0){    // Checks for consecutive zeroes.
                    i--;
                }
            }
            cnt++;
        }
    }
};
