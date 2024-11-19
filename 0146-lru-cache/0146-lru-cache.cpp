class LRUCache {
public:
    int capacity;
    list<int> usageList;
    unordered_map<int, pair<int, list<int>::iterator>> cache;

    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        usageList.erase(cache[key].second);
        usageList.push_front(key);
        cache[key].second = usageList.begin();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            usageList.erase(cache[key].second);
            usageList.push_front(key);
            cache[key] = {value, usageList.begin()};
            return;
        }
        if (cache.size() == capacity) {
            int lruKey = usageList.back();
            usageList.pop_back();
            cache.erase(lruKey);
        }
        usageList.push_front(key);
        cache[key] = {value, usageList.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */