class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities;
        for (const auto path : paths) {
            cities.insert(path[0]);
        }
        for (const auto path: paths) {
            if (cities.find(path[1]) == cities.end()) {
                return path[1];
            }
        }
        return "";
    }
};

// class Solution {
// public:
//     string destCity(vector<vector<string>>& paths) {
//         for (int a = 0; a < paths.size() - 1; a++) {
//             for (int b = 0; b < paths.size() - a - 1; b++) {
//                 if (paths[a][0] == paths[a+1][1] && paths[a][1] != paths[a+1][0]) {
//                     vector<string> temp = paths[a];
//                     paths[a] = paths[a+1];
//                     paths[a+1] = temp;
//                 }
//             }
//         }
//         int i = 0;
//         for (i = 0; i < paths.size() - 1; i++) {
//             if (paths[i][1] == paths[i+1][0]) {
//                 continue;
//             } else {
//                 return paths[i][1];
//             }
//         }
//         return paths[i][1];
//     }
// };