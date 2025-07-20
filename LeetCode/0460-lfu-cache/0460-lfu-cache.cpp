class LFUCache {
private:
    int capacity;
    int minFreq;
    int size;
    
    unordered_map<int, int> keyToValue;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, list<int>> freqToList;
    unordered_map<int, list<int>::iterator> keyToIterator;
    
    void updateFrequency(int key) {
        int freq = keyToFreq[key];
        freqToList[freq].erase(keyToIterator[key]);
        if (freqToList[freq].empty() && freq == minFreq) {
            minFreq++;
        }
        
        keyToFreq[key]++;
        int newFreq = keyToFreq[key];
        
        freqToList[newFreq].push_back(key);
        keyToIterator[key] = --freqToList[newFreq].end();
    }
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
        this->size = 0;
    }
    
    int get(int key) {
        if (keyToValue.find(key) == keyToValue.end()) {
            return -1;
        }
        updateFrequency(key);
        return keyToValue[key];
    }
    
    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        
        if (keyToValue.find(key) != keyToValue.end()) {
            keyToValue[key] = value;
            updateFrequency(key);
            return;
        }
        
        if (size == capacity) {
            int keyToRemove = freqToList[minFreq].front();
            freqToList[minFreq].pop_front();
            keyToValue.erase(keyToRemove);
            keyToFreq.erase(keyToRemove);
            keyToIterator.erase(keyToRemove);
            size--;
        }
        
        keyToValue[key] = value;
        keyToFreq[key] = 1;
        minFreq = 1;
        freqToList[1].push_back(key);
        keyToIterator[key] = --freqToList[1].end();
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */