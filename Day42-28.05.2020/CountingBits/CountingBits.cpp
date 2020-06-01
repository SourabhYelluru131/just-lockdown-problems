//  https://leetcode.com/problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int num) {
        #pragma GCC optimize ("Ofast")
        static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();   // 2 magical lines to speed up code :wink:
        vector<int> count(num+1,0);
        for(int i=0;i<=num;i++){
            count[i] = count[i>>1]+i%2;
        }
        return count;
    }
};
