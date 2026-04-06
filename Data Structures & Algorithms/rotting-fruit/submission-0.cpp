class Solution {
private:
    bool isInBoundAndFresh(vector<vector<int>>& grid, int i, int j, int m, int n){
        return i>=0 && i<n && j>=0 && j<m && grid[i][j]==1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotted;
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    rotted.push({i, j});
        
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int minute = 0;
        while(fresh && rotted.size()){
            int rotteds = rotted.size();
            while(rotteds--){
                pair<int,int> cur = rotted.front();
                rotted.pop();
                for(int d=0; d<dir.size(); d++){
                    int i = cur.first + dir[d][0];
                    int j = cur.second + dir[d][1];
                    if(isInBoundAndFresh(grid, i, j, m, n)){
                        grid[i][j] = 2;
                        fresh--;
                        rotted.push({i, j});
                    }
                }
            }
            minute++;
        }
        return fresh? -1 : minute;
    }
};
