//  https://leetcode.com/problems/two-city-scheduling/
class Solution {
public:
    void insertinvec(vector<int> x, vector<vector<int>>& AB, int a){
        int i;
        for(i=0;i<AB.size();i++){
            if(AB[i][a]-AB[i][1-a]>=x[a]-x[1-a]){
                AB.insert(AB.begin()+i,x);
                return;
            }
        }
        if(i==AB.size()){
            AB.push_back(x);
        }
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> A,B;
        for(auto x:costs){
            if(x[0]<x[1]){
                if(A.size()<costs.size()/2){
                    insertinvec(x,A,0);
                }
                else{
                    if(A[A.size()-1][0]+x[1]<A[A.size()-1][1]+x[0]) insertinvec(x,B,1);
                    else{
                        insertinvec(A[A.size()-1],B,1);
                        A.pop_back();
                        insertinvec(x,A,0);
                    }
                }
            }
            else{
                if(B.size()<costs.size()/2) insertinvec(x,B,1);
                else{
                    if(B[B.size()-1][1]+x[0]<B[B.size()-1][0]+x[1]) insertinvec(x,A,0);
                    else{
                        insertinvec(B[B.size()-1],A,0);
                        B.pop_back();
                        insertinvec(x,B,1);
                    }
                }
            }
        }
        int sum=0;
        for(auto x:A) sum+=x[0];
        for(auto x:B) sum+=x[1];
        return sum;
    }
};
