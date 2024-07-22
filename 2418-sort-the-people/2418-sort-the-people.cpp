class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = make_pair(heights[i], names[i]);
        }
        sort(rbegin(vec), rend(vec));
        for (int i = 0; i < n; i++) {
            names[i] = vec[i].second;
        }
        return names;
    }
};





// class Solution {
// public:
//     vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         int n = names.size();
//         vector<pair<string, int>> vec(n);
//         for (int i = 0; i < n; i++) {
//             vec[i] = make_pair(names[i], heights[i]);
//         }
//         auto cmp = [](auto &a, auto &b) {
//             return a.second > b.second;
//         };
//         sort(vec.begin(), vec.end(), cmp);
//         for (int i = 0; i < n; i++) {
//             names[i] = vec[i].first;
//         }
//         return names;
//     }
// };