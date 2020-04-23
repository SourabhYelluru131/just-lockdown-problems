//  https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int sum=0,count=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(map[sum-k]){
                count += map[sum-k];
            }
            map[sum]++;
            if(sum==k){
                count++;
            }
        }
        return count;
    }
};
