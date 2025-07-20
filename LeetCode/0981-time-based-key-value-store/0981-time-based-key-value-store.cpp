class TimeMap {
public:
    unordered_map<string, map<int, string>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound(timestamp);
        return it == mp[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */




// TLE
// class TimeMap {
// public:
//     unordered_map<string, vector<pair<int, string>>> data;

//     TimeMap() {
//     }
    
//     void set(string key, string value, int timestamp) {
//         data[key].emplace_back(timestamp, value);
//     }
    
//     string get(string key, int timestamp) {
//         if (data.find(key) == data.end()) {
//             return "";
//         }
//         auto timeValuePair = data[key];
//         int left = 0, right = timeValuePair.size() - 1;
//         string result = "";
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (timeValuePair[mid].first <= timestamp) {
//                 result = timeValuePair[mid].second;
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }
//         return result;
//     }
// };

// /**
//  * Your TimeMap object will be instantiated and called as such:
//  * TimeMap* obj = new TimeMap();
//  * obj->set(key,value,timestamp);
//  * string param_2 = obj->get(key,timestamp);
//  */