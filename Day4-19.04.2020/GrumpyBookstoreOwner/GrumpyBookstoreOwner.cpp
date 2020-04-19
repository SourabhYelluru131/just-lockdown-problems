//    https://leetcode.com/problems/grumpy-bookstore-owner/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int maxSatisfied=0,totalSatisfaction=0;
        for(int i=0;i<grumpy.size();i++){
            if(!grumpy[i]){
                totalSatisfaction += customers[i];
            }
        }
        int beg=0,stop=0,sum=0;
        for(;stop<grumpy.size();stop++){
            if(!grumpy[stop]){
                totalSatisfaction -= customers[stop];
            }
            sum += customers[stop];                  //Removing if present in Total Sum to partial Sum
            if(stop-beg+1>=X){
                int totSum = sum + totalSatisfaction;
                if(totSum>maxSatisfied){
                    maxSatisfied = totSum;
                }
                if(!grumpy[beg]){
                    totalSatisfaction += customers[beg];
                }
                sum -= customers[beg];
                beg++;
            }
        }
        return maxSatisfied;
    }
};
