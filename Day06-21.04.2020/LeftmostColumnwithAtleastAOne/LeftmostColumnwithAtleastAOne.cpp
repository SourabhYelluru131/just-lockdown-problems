//    https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3306/
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int ans=-1;
        vector<int> dim = binaryMatrix.dimensions();   
        int i=0,j=dim[1]-1;
        while(i<dim[0] && j>=0){
            if(binaryMatrix.get(i,j)){
                ans=j;
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
