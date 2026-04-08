class Solution {
    void dfs(vector<vector<int>>& adjs, vector<bool>& visited, int node){
        if(visited[node])return ;
        visited[node] = true;
        for(int adj : adjs[node])
            dfs(adjs, visited, adj);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjs(n);
        vector<bool> visited(n, false);
        int components = 0;
        for(vector<int>& edge : edges){
            int node1 = edge[0], node2 = edge[1];
            adjs[node1].push_back(node2);
            adjs[node2].push_back(node1);
        }
        for(int node=0; node<n; node++){
            if(visited[node] == false){
                components++;
                dfs(adjs, visited, node);
            }
        }
        return components;

    }
};
