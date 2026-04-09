class Solution {
private:
    bool isNeighbor(string a, string b){
        int diff = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] == b[i])continue;
            diff++;
            if(diff > 1)return false;
        }
        return diff == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool endExist = false;
        for(string& word : wordList)
            if(word == endWord)endExist = true;
        if(!endExist)return 0;
        int n = wordList.size();
        vector<vector<int>> adjs(n+1);
        wordList.push_back(beginWord);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=n; j++){
                if(isNeighbor(wordList[i], wordList[j])){
                    adjs[i].push_back(j);
                    adjs[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n+1, false);
        queue<int> q;
        int series = 0;
        q.push(n);
        visited[n] = true;
        while(!q.empty()){
            series++;
            int qs = q.size();
            while(qs--){
                int i = q.front(); q.pop();
                if(wordList[i] == endWord)return series;
                visited[i] = true;
                for(int adj : adjs[i])
                    if(!visited[adj])
                        q.push(adj);
            }
        }
        return 0;
    }
};