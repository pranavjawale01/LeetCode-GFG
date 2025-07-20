class LFUCache {
    private int capacity;
    private int minFreq;
    private int size;
    
    private HashMap<Integer, Integer> keyToValue;
    private HashMap<Integer, Integer> keyToFreq;
    private HashMap<Integer, LinkedHashSet<Integer>> freqToList;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.minFreq = 0;
        this.size = 0;
        this.keyToValue = new HashMap<>();
        this.keyToFreq = new HashMap<>();
        this.freqToList = new HashMap<>();
    }
    
    public int get(int key) {
        if (!keyToValue.containsKey(key)) {
            return -1;
        }
        updateFrequency(key);
        return keyToValue.get(key);
    }
    
    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        
        if (keyToValue.containsKey(key)) {
            keyToValue.put(key, value);
            updateFrequency(key);
            return;
        }
        
        if (size == capacity) {
            int keyToRemove = freqToList.get(minFreq).iterator().next();
            freqToList.get(minFreq).remove(keyToRemove);
            keyToValue.remove(keyToRemove);
            keyToFreq.remove(keyToRemove);
            size--;
        }
        
        keyToValue.put(key, value);
        keyToFreq.put(key, 1);
        minFreq = 1;
        freqToList.computeIfAbsent(1, k -> new LinkedHashSet<>()).add(key);
        size++;
    }
    
    private void updateFrequency(int key) {
        int freq = keyToFreq.get(key);
        freqToList.get(freq).remove(key);
        
        if (freqToList.get(freq).isEmpty() && freq == minFreq) {
            minFreq++;
        }
        
        keyToFreq.put(key, freq + 1);
        freqToList.computeIfAbsent(freq + 1, k -> new LinkedHashSet<>()).add(key);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */