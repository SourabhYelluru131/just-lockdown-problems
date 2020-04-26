// https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void reverse(vector<int>& nums, int beg, int end){             // Using Reverse method
        for(int i=beg;i<end;i++)
        {
            int temp;
            if(i<end+beg-i){
                temp = nums[i];
                nums[i]= nums[end+beg-i];
                nums[end+beg-i]= temp;
            }
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n;
        n = nums.size();
        k=k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};
