//https://leetcode.com/problems/single-number-iii/
/*class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==2) return nums;
        unordered_map<int,int> hash;
        for(int x:nums){
            hash[x]++;
            if(hash[x]==2) hash[x]=0;
        }
        vector<int> sol;
        for(auto it:hash) if(it.second>0) sol.push_back(it.first);
        return sol;
    }
};*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int n : nums) x ^= n;
        int s = __builtin_ctz(x);
        int c = 1 << s;
        vector<int> out(2);
        for (int n : nums) out[(c & n) >> s] ^= n;
        return out;
    }
};

static const auto fast = []() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;
} ();
