//  https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxt=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxt){
                return false;
            }
            if(maxt>=nums.size()-1){
                return true;
            }
            int a = i+nums[i];
            maxt = max(a,maxt); 
        }
        return false;
    }
};
