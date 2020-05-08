//https://leetcode.com/problems/check-if-it-is-a-straight-line/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        float m;
        if(x2!=x1) m = (y2-y1)/(x2-x1);
        else m = INT_MAX;
        float c = y1 - m*x1;
        for(auto e : coordinates){
            if(e[1]-m*e[0]-c) return false;
        }
        return true;
    }
};
