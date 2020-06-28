//  https://leetcode.com/problems/largest-divisible-subset/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        if(nums.size()==1) return nums;
        if(!nums.size()) return res;
        sort(nums.begin(),nums.end());
        int maxlen=0,ind=INT_MAX,parind,maxparind;
        vector<int> dp(nums.size(),1);
        vector<int> parent(nums.size(),-1);
        for(int i=nums.size()-1;i>=0;i--){
            parind = 0,maxparind = 0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]%nums[i]==0){
                    parind = j;
                    if(maxparind==0) maxparind = j;
                    else if(dp[maxparind] < dp[j]) maxparind = j;
                    dp[i] = 1+dp[maxparind];
                    parent[i] = maxparind;
                    maxlen = max(maxlen,dp[i]);
                    if(maxlen==dp[i]) ind = i;
                }
            }
        }
        if(ind==INT_MAX){
            res.push_back(nums[0]);
            return res;
        }
        do{
            res.push_back(nums[ind]);
            ind = parent[ind];
        }while(ind!=-1);
        return res;
    }
};
