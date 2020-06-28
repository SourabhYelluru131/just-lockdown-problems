//   https://leetcode.com/problems/power-of-two/ 
//  Nice Soln!
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&(n-1));
    }
};
