class Solution {
private:
    int islandArea(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + islandArea(grid, i+1, j) + islandArea(grid, i-1, j)
                + islandArea(grid, i, j-1) + islandArea(grid, i, j+1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    int area = islandArea(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
