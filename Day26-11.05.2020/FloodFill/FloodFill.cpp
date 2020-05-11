//https://leetcode.com/problems/flood-fill/
class Solution {
    int a,b;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(); if (m == 0) return image;
        int n = image[0].size(); if (n == 0) return image;
        a=m;
        b=n;
        int c = image[sr][sc];
        if (c != newColor)
            dfs(image,sr, sc, c, newColor);
        return image;
    }
    
private:
    void dfs(vector<vector<int>>& image, int x, int y, int color, int newcolor) {
        if (x < 0 || x >= a || y < 0 || y >= b || image[x][y] != color) return;
        image[x][y] = newcolor;
        dfs(image, x-1, y, color, newcolor);
        dfs(image, x+1, y, color, newcolor);
        dfs(image, x, y-1, color, newcolor);
        dfs(image, x, y+1, color, newcolor);
    }
};
