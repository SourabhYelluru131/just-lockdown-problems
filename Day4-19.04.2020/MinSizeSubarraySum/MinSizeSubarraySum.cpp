//    https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()){
            int start=0,end=0,sum=0,minlen=INT_MAX;
            for(;end<nums.size();end++){
                sum+=nums[end];
                while(s<=sum){
                    minlen = min(minlen,end-start+1);
                    sum -= nums[start++];
                }
            }
            if(minlen==INT_MAX){
                return 0;
            }
            else{
                return minlen;
            }
        }
        else{
            return 0;
        }
    }
};
