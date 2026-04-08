class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjs(n+1);
        vector<int> indegrees(n+1, 0);
        queue<int> leaf;
        for(const auto& edge : edges){
            int u = edge[0], v = edge[1];
            adjs[u].push_back(v);
            adjs[v].push_back(u);
            indegrees[u]++;
            indegrees[v]++;
        }
        for(int i=1; i<=n; i++)
            if(indegrees[i] == 1)
                leaf.push(i);
        
        while(!leaf.empty()){
            int node = leaf.front(); leaf.pop();
            indegrees[node]--;
            for(const int adj : adjs[node]){
                indegrees[adj]--;
                if(indegrees[adj] == 1)
                    leaf.push(adj);
            }
        }
        for(int i=n-1; i>=0; i--){
            int u = edges[i][0], v = edges[i][1];
            if(indegrees[u] > 1 && indegrees[v] > 1)
                return {u, v};
        }
        return {};
    }
};