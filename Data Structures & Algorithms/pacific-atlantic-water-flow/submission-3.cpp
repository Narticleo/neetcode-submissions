class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j, int prev){
        if(i<0 || j<0 || i==heights.size() || j==heights[0].size() || heights[i][j] < prev || ocean[i][j])
            return ;
        ocean[i][j] = true;
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for(int d=0; d<dir.size(); d++){
            dfs(heights, ocean, i+dir[d][0], j+dir[d][1], heights[i][j]);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));        
        for(int i=0; i<n; i++){
            dfs(heights, pacific, i, 0, 0);
            dfs(heights, atlantic, i, m-1, 0);
        }
        for(int j=0; j<m; j++){
            dfs(heights, pacific, 0, j, 0);
            dfs(heights, atlantic, n-1, j, 0);
        }
        vector<vector<int>> result;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
                    
        return result;
    }
};
