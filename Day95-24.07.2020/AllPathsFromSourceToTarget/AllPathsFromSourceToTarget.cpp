//https://leetcode.com/problems/all-paths-from-source-to-target/
class Solution {
public:
    void dfs(vector<vector<int>>&g , vector<vector<int>>& paths, vector<int>& path,int cur){
        path.push_back(cur);
        if(cur==g.size()-1) paths.push_back(path);
        else for(auto it:g[cur]) dfs(g,paths,path,it);
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> sol;
        vector<int> path;
        dfs(graph,sol,path,0);
        return sol;
    }
};
