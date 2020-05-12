//https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int prev = nums[0];
        int rep=0;
        int ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==prev) rep++;
            else{
                if(!rep){
                    ans = prev;
                    break;
                }
                prev=nums[i];
                rep=0;
            }
        }
        return ans;
    }
};
