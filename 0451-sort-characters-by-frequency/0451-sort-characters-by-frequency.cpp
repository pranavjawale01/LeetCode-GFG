class Solution {
public:
    typedef pair<char, int> P;

    struct lambda  {
        bool operator()(P &p1, P &p2) {
            return p1.second < p2.second;
        }
    };

    string frequencySort(string s) {
        priority_queue<P, vector<P>, lambda> pq;
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        for (auto &it : mp) {
            pq.push({it.first, it.second});
        }
        string result = "";
        while (!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            result += string(temp.second, temp.first);
        }
        return result;
    }
};

// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char, int> mp;
//         for (char c : s) {
//             mp[c]++;
//         }
//         auto comparator = [&] (char a, char b) {
//             if (mp[a] == mp[b]) {
//                 return a < b;
//             }
//             return mp[a] > mp[b];
//         };
//         sort(s.begin(), s.end(), comparator);
//         return s;
//     }
// };