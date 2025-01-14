class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        for (int i = 1; i < folder.size(); i++) {
            string currFolder = folder[i];
            string lastFolder = ans.back();
            lastFolder += "/";
            if (currFolder.find(lastFolder) != 0) {
                ans.push_back(currFolder);
            }
        }
        return ans;
    }
};




// class Solution {
// public:
//     vector<string> removeSubfolders(vector<string>& folder) {
//         unordered_set<string> st(folder.begin(), folder.end());
//         vector<string> ans;
//         for (auto &x : folder) {
//             bool isSubFolder = false;
//             string res = x;
//             while (!x.empty()) {
//                 size_t position = x.find_last_of('/');
//                 x = x.substr(0, position);
//                 if (st.find(x) != st.end()) {
//                     isSubFolder = true;
//                     break;
//                 }
//             }
//             if (!isSubFolder) {
//                 ans.push_back(res);
//             }
//         }
//         return ans;
//     }
// };