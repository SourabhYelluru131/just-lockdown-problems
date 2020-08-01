//https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //Set up the graph : index all courses, values all direct dependents (courses for which you must first take the index course in order to take)
        vector<vector<int>> allDeps(numCourses);
        for (auto& p : prerequisites)
            allDeps[p[1]].push_back(p[0]);
        
        //Perform a topological sort on the matrix to get nodes in linear order of priority
        return TopoSort(allDeps);
    }
    
    vector<int> TopoSort(vector<vector<int>>& allDeps) {
        int n = allDeps.size();
        vector<int> ans;
        
        //Count and store the number of direct requirements of each dependent course
        //This record will maintain a running count of dependent courses that have not yet been traversed and help identify courses that should be added when all requirements have been taken (count reaches 0)
        vector<int> requirements(n, 0);
        for (auto& course : allDeps)
            for (auto& dep : course)
                requirements[dep]++;
        
        //Set up the BFS, search for courses with no direct requirements to use as a starting point of the traversal of the graph
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (requirements[i] == 0)
                q.push(i);
        
        //BFS traversal of the graph
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            n--;
            ans.push_back(cur);               //Add the current course
            for (auto& p : allDeps[cur]){     //For each direct dependent of the current course
                requirements[p]--;            //Indicate that another requirement has been met
                if (requirements[p] == 0)     //If the course has no more unmet requirements, add to order
                    q.push(p);
            }
        }
        
        //If we encountered all courses during BFS traversal, return calculated order else empty vector
        return (n == 0)? ans : vector<int>(0);
    }
};
