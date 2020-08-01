//https://leetcode.com/problems/powx-n/
class Solution {
public:
    double myPow(double x, int n) {
        if(x==1) return 1;
        if(n == INT_MIN){
            x = x * x;
            n = n/2;
        }
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    }
};
