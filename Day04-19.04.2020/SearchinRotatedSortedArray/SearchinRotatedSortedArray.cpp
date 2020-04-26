//    https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3304/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i,flag=0;
        if(nums.size()==0){
            return -1;
        }
        else{
            if(target>=nums[0]){
                int last=0;
                for(i=0;i<nums.size();i++){
                    if(nums[i]>=last){
                        if(nums[i]==target){
                            flag = 1;
                            break;
                        }
                        else
                        {
                            last = nums[i];
                        }
                    }
                }
            }
            else{
                int last=nums[nums.size()-1];
                for(i=nums.size()-1;i>=0;i--){
                    if(nums[i]<=last){
                        if(nums[i]==target){
                            flag = 1;
                            break;
                        }
                        else{
                            last = nums[i];
                        }
                    }
                }
            }
            if(flag){
                return i;
            }
            else{
                return -1;
            }
        }
    }
};
