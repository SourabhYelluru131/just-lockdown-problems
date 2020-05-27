//  https://leetcode.com/problems/contiguous-array/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        #pragma GCC optimize ("Ofast")
        static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } (); 
        unordered_map<int,int> hash;
        int maxlen=0,count=0;
        hash[0]=-1;
        for(int i=0;i<nums.size();i++){
            int a;
            if(nums[i]==1) a=1;
            else a = -1;
            count += a;
            if(hash.find(count)!=hash.end()) maxlen = max(maxlen,i-hash[count]);
            else hash[count]=i;
        }
        return maxlen;
    }
};
