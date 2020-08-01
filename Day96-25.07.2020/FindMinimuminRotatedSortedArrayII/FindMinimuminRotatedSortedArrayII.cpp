//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int minim = nums[0],i=1;
        while(i<nums.size() && nums[i]>=nums[i-1]) i++;
        if(i==nums.size()) return minim;
        else return nums[i];
    }
};
