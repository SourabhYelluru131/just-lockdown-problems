// https://leetcode.com/problems/arranging-coins/
class Solution {
public:
    int arrangeCoins(int n) {
        long int na = n;
        na *= 2;
        double sqt = sqrt(na+1/4);
        int res = sqt-0.5;
        return res;
    }
};
