//  https://leetcode.com/problems/h-index-ii/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(!citations.size()) return 0;
        int i;
        for(i=citations.size()-1;i>=0;i--){
            if((citations.size()-i)>citations[i]){
                i++;
                break;
            }
            if(citations.size()-i==citations[i]){
                break;
            }
        }
        if(i==-1) return citations.size();
        return citations.size()-i;
    }
};
