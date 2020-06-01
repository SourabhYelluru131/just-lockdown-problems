//  https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool topSort(unordered_map<int,vector<int>> nbrs,vector<int> indeg)
    {
        deque<int> nodes;
        for(int i=0;i<indeg.size();i++)
            if(indeg[i]==0)
                nodes.push_back(i);

        int count = 0;
        while(!nodes.empty())
        {
            int u = nodes.front();
            nodes.pop_front();
            for(int i=0;i<nbrs[u].size();i++)
                if(--indeg[nbrs[u][i]]==0)
                    nodes.push_back(nbrs[u][i]);

            count++;
        }
        if(count!=indeg.size())
            return false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>> nbrs;
        vector<int> indeg(numCourses,0);

        for(int i=0;i<prerequisites.size();i++)
        {   
            nbrs[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }

        return topSort(nbrs,indeg);
    }
};
