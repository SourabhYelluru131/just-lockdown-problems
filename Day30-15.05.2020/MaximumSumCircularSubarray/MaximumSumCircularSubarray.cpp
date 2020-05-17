//https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(!A.size()) return 0;
        int sum = A[0];
        int maxSoFar = A[0];
        int maxTotal = A[0];
        int minSoFar = A[0];
        int minTotal = A[0];
        for(int i=1;i<A.size();i++){
            maxSoFar = max(A[i],A[i]+maxSoFar);
            maxTotal = max(maxTotal,maxSoFar);
            
            minSoFar = min(A[i],A[i]+minSoFar);
            minTotal = min(minTotal,minSoFar);
            
            sum+=A[i];
            
        }
        if(sum==minTotal) return maxTotal;
        else return max(sum - minTotal, maxTotal);
    }
};
