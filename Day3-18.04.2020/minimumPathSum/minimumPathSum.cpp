//  https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=0,n=0;
        m = grid.size();
        if(!m){
            return 0;
        }
        else{
            n = grid[0].size();
            vector<vector<int>> newGrid = minimize(grid,m,n);
            return newGrid[m-1][n-1];
        }
    }
private:
    vector<vector<int>> minimize(vector<vector<int>>& grid, int m, int n){
        vector<vector<int>> newgrid(m,vector<int>(n));
        int fs = 0;
        for(int i=0;i<n;i++){
            fs = fs + grid[0][i];
            newgrid[0][i] = fs;
        }
        fs = 0;
        for(int i=0;i<m;i++){
            fs = fs + grid[i][0];
            newgrid[i][0] = fs;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int a =  min(newgrid[i-1][j],newgrid[i][j-1]); //Checks lowest path Sum to reach 1 step before grid[i][j]
                newgrid[i][j] = grid[i][j] + a; 
            }
        }
    return newgrid;
    }
};
