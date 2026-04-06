class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool cols[9][9] = {false};
        bool rows[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')continue;
                int num = board[i][j]-'1';
                int box = 3*(i/3) + j/3;
                if(cols[i][num] || rows[j][num] || boxes[box][num])
                    return false;
                cols[i][num] = rows[j][num] = boxes[box][num] = true;
            }
        }
        return true;
    }
};