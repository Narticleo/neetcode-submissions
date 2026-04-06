class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> result;
        for(auto str : strs){
            string ori = str;
            sort(str.begin(), str.end());
            umap[str].push_back(ori);
        }
        for(auto vec : umap)
            result.push_back(vec.second);
        return result;
    }
};
