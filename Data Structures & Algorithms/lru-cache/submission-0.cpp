class LRUCache {
private:
    int elements = 0;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> addrs; 
    int size;
    list<int> history;
    void removeLRU(){
        int lru = history.front();
        addrs.erase(lru);
        cache.erase(lru);
        history.pop_front();
        elements = size;
    }
    void updateHistory(int key){
        if(cache.count(key))
            history.erase(addrs[key]);
        history.push_back(key);
        addrs[key] = prev(history.end());
    }
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end())return -1;
        updateHistory(key);
        return cache[key]; 
    }
    
    void put(int key, int value) {
        if(!cache.count(key))
            elements++;
        updateHistory(key);
        cache[key] = value;
        if(elements > size)
            removeLRU();

    }
};