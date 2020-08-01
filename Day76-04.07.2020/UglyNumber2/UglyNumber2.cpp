//https://leetcode.com/problems/ugly-number-ii/
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0){
            return 0;
        }
        int a2=0,a3=0,a5=0;
        long int k[n];
        k[0]=1;
        for(int i=1;i<n;i++){
            k[i] = min(min(k[a2]*2,k[a3]*3),k[a5]*5);
            if(k[i] == k[a2]*2){
                a2++;
            }
            if(k[i] == k[a3]*3){
                    a3++;
            }
            if(k[i] == k[a5]*5){
                    a5++;
            }
        }
        return k[n-1];
    }
};
