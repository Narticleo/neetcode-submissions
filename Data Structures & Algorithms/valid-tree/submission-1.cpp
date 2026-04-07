class Solution {
    int findRoot(vector<int>& parent, int node){
        return parent[node] == node? node : findRoot(parent, parent[node]);
    }
    bool setUnion(vector<int>& parent, vector<int> elements, int node1, int node2){
        int main = findRoot(parent, node1);
        int branch = findRoot(parent, node2);
        if(main == branch)return false;
        if(elements[main] < elements[branch])swap(main, branch);
        elements[main] += elements[branch];
        parent[branch] = parent[main];
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==0)return true;
        vector<int> parent(n);
        vector<int> elements(n, 1);
        int components = n;
        for(int i=0; i<n; i++)
            parent[i] = i;
        for(auto& edge : edges)
            if(setUnion(parent, elements, edge[0], edge[1]))
                components--;
            else
                return false;
        
        return components == 1;
    }
};
