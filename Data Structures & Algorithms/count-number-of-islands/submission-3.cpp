class Solution {
private:
    void searchIslands(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1)return ;
        if(grid[i][j] == '0')return ;
        grid[i][j] = '0';
        searchIslands(grid, i, j+1);
        searchIslands(grid, i, j-1);
        searchIslands(grid, i+1, j);
        searchIslands(grid, i-1, j);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)return 0;
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == '1'){
                    islands++;
                    searchIslands(grid, i, j);
                }
        return islands;
            
    }
};