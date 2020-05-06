//      https://leetcode.com/problems/majority-element/
//      Not optimum solution
//      First try using hashmaps, second using sort
//      Hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold;
        if(n%2==0) threshold = n/2;
        else threshold = (n+1)/2;
        unordered_map<int,int> hash;
        for(int x:nums){
            hash[x]++;
            if(hash[x]>=threshold){
                return x;
            }
        }
        return 0;
    }
};
