class Solution {
private:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    bool searchWord(vector<vector<char>>& board, vector<vector<bool>>& visted, string& word, int idx, int i, int j, int w, int h){
        if(idx == word.size())return true;
        if(i < 0 || j < 0 || i >= w || j >= h )return false;
        if(word[idx] != board[j][i] || visted[j][i])return false;
        visted[j][i] = true;
        for(int k=0; k<4; k++)
            if(searchWord(board, visted, word, idx+1, i+dx[k], j+dy[k], w, h))
                return true;
        visted[j][i] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int w = board[0].size();
        int h = board.size();
        vector<vector<bool>> visted(h, vector<bool>(w, false));
        for(int i=0; i<w; i++)
            for(int j=0; j<h; j++)
                if(searchWord(board, visted, word, 0, i, j, w, h))
                    return true;
        
        return false;
    }
};
