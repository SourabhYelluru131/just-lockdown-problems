// https://leetcode.com/problems/bitwise-and-of-numbers-range/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count=0;
        while(m!=n){           //Until m is equal to n, we keep right shifting both n;
            m = m >> 1;
            n = n >> 1;
            count++;
        }
        m = m << count;        // Now left shift until we reach original length
        return m;
    }
};
