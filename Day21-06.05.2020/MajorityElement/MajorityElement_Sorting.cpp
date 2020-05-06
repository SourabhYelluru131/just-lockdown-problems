//      https://leetcode.com/problems/majority-element/
//      Not optimum solution
//      First try using hashmaps, second using sort
//      Sort
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold,prev=0,count=0;
        if(n%2==0) threshold = n/2;
        else threshold = (n+1)/2;
        sort(nums.begin(),nums.end());
        for(int x:nums){
            if(x!=prev){
                count = 1;
                prev = x;
            }
            else count++;
            if(count>=threshold){
                return x;
            }
        }
        return 0;
    }
};

