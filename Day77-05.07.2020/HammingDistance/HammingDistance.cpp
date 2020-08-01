//https://leetcode.com/problems/hamming-distance/
class Solution {
public:
    int countones(int a){
        int count = 0;
        while(a){
            if(a%2) count++;
            a = a>>1;
        }
        return count;
    }
    int hammingDistance(int x, int y) {
        return countones(x^y);
    }
};
