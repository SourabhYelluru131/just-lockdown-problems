//https://leetcode.com/problems/island-perimeter/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int land=0,neighbours=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    land++;
                    if(i!=grid.size()-1 && grid[i+1][j]==1) neighbours++;
                    if(j!=grid[0].size()-1 && grid[i][j+1]==1) neighbours++;
                }
            }
        }
        return 4*land-2*neighbours;
    }
};
