class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> umap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!umap.count(key))return "";
        vector<pair<string,int>>& vec = umap[key];
        int l = 0; int r = vec.size()-1;
        if(vec[l].second > timestamp)return "";
        while(l<r){
            int m = l + (r - l) / 2;
            if(vec[m].second > timestamp)
                r = m - 1;
            else
                l = m;
            if(vec[r].second <= timestamp)return vec[r].first;
            if(vec[l+1].second > timestamp)return vec[l].first;
        }
        return vec[r].first;
    }
};