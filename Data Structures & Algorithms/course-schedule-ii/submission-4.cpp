class Solution {
    bool dfs(vector<vector<int>>& pre, vector<queue<int>>& required, vector<bool>& visited, vector<bool>& learned, vector<int>& order, int course){
        if(visited[course])return false;
        if(learned[course])return true;
        visited[course] = true;

        while(!required[course].empty()){
            int pretake = required[course].front(); required[course].pop();
            if(dfs(pre, required, visited, learned, order, pretake) == false)return false;
        }
        order.push_back(course);
        learned[course] = true;
        visited[course] = false;
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<queue<int>> required(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> learned(numCourses, false);
        vector<bool> needed(numCourses, false);
        vector<int> order;
        vector<int> last;
        set<int> courseNeedRetake;
        for(int i=0; i<prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            required[course].push(pre);
            needed[pre] = true;
            courseNeedRetake.insert(course);
        }
        for(int course=0; course<numCourses; course++)
            if(needed[course] == false)last.push_back(course);
        
        if(courseNeedRetake.size() == numCourses || last.size() == 0)return {};
        
        for(int course=0; course<last.size(); course++){
            if(dfs(prerequisites, required, visited, learned, order, last[course]))
                continue;
            return {};            
        }
        
        return order.size() == numCourses? order : vector<int>{};
    }
};