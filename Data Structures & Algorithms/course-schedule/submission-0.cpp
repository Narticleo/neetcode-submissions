class Solution {
    bool dfs(vector<vector<int>>& pre, vector<queue<int>>& required, vector<bool>& visited, int course){
        if(visited[course])return false;
        visited[course] = true;

        while(!required[course].empty()){
            int pretake = required[course].front(); required[course].pop();
            if(dfs(pre, required, visited, pretake) == false)return false;
        }

        visited[course] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<queue<int>> required(numCourses);
        vector<bool> visited(numCourses, false);
        for(int i=0; i<prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            required[course].push(pre);
        }

        for(int course=0; course<numCourses; course++)
            if(dfs(prerequisites, required, visited, course) == false)return false;
        
        return true;
    }
};