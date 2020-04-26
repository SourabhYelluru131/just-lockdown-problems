//    https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int down = obstacleGrid.size();
        if(!down){
            return 0;
        }
        int right = obstacleGrid[0].size();
        vector<vector<long int>> PathGrid(down,vector<long int>(right));
        int i,j;
        if(obstacleGrid[0][0]){
            PathGrid[0][0]=0;
        }
        else{
            PathGrid[0][0]=1;
        }
        for(i=0;i<down;i++){
            for(j=0;j<right;j++){
                if(i && j){
                    if(!obstacleGrid[i][j]){
                        PathGrid[i][j]=PathGrid[i-1][j]+PathGrid[i][j-1];
                    }
                    else{
                        PathGrid[i][j]=0;
                    }
                }
                else{
                    if(j!=0){
                        if(!obstacleGrid[i][j]){
                            PathGrid[i][j]=PathGrid[i][j-1];
                        }
                        else{
                            PathGrid[i][j]=0;
                        }
                    }
                    else{
                        if(i==0 && j==0){
                            continue;
                        }
                        else{
                            if(!obstacleGrid[i][j]){
                                PathGrid[i][j]=PathGrid[i-1][j];
                            }
                            else{
                                PathGrid[i][j]=0;
                            }
                        }
                    }
                }
            }
        }
        return PathGrid[down-1][right-1];
    }
};
