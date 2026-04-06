class Solution {
private:
    void backtracking(vector<vector<string>>& result, vector<string>& board, vector<vector<bool>>& record, int j, int n){  
        if(j == n){
            result.push_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            if(record[0][i] || record[1][i-j+n-1] || record[2][i+j])continue;
            setRecordAndBoard(record, board, true, i, j, n);
            backtracking(result, board, record, j+1, n);
            setRecordAndBoard(record, board, false, i, j, n);
        }
    }
    void setRecordAndBoard(vector<vector<bool>>& record, vector<string>& board, bool value, int i, int j, int n){
        record[0][i] = value;
        record[1][i-j+n-1] = value;
        record[2][i+j] = value;
        if(value)board.push_back(string(i, '.') + 'Q' + string(n-i-1, '.'));
        else board.pop_back();
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> record = {
        vector<bool>(n, false), //row
        vector<bool>(2*n-1, false), //slash
        vector<bool>(2*n-1, false) //back slash
        };
        vector<vector<string>> result;
        vector<string> board;
        backtracking(result, board, record, 0, n);
        return result;
    }
};
