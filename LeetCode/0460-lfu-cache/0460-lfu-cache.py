class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.min_freq = 0
        self.size = 0
        self.key_to_value = {}
        self.key_to_freq = {} 
        self.freq_to_keys = defaultdict(OrderedDict)

    def get(self, key: int) -> int:
        if key not in self.key_to_value:
            return -1
        self._update_frequency(key)
        return self.key_to_value[key]

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        
        if key in self.key_to_value:
            self.key_to_value[key] = value
            self._update_frequency(key)
            return
        
        if self.size == self.capacity:
            self._evict_least_frequent()
        
        self.key_to_value[key] = value
        self.key_to_freq[key] = 1
        self.freq_to_keys[1][key] = None
        self.min_freq = 1
        self.size += 1

    def _update_frequency(self, key: int):
        freq = self.key_to_freq[key]
        del self.freq_to_keys[freq][key]  

        if not self.freq_to_keys[freq]:
            del self.freq_to_keys[freq]
            if freq == self.min_freq:
                self.min_freq += 1

        self.key_to_freq[key] += 1
        new_freq = self.key_to_freq[key]
        self.freq_to_keys[new_freq][key] = None

    def _evict_least_frequent(self):
        least_freq_keys = self.freq_to_keys[self.min_freq]
        key_to_remove, _ = least_freq_keys.popitem(last=False) 

        if not least_freq_keys:
            del self.freq_to_keys[self.min_freq]

        del self.key_to_value[key_to_remove]
        del self.key_to_freq[key_to_remove]
        self.size -= 1

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)