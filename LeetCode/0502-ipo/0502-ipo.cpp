class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {capital[i], profits[i]};
        }
        sort(vec.begin(), vec.end());
        int i = 0;
        priority_queue<int> pq;
        while (k--) {
            while (i < n && vec[i].first <= w) {
                pq.push(vec[i].second);
                i++;
            }
            if (pq.empty()) {
                break;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};



// heap-buffer-overflow
// class Solution {
// public:
//     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
//         vector<pair<int, int>> vec(n);
//         int n = profits.size();
//         for (int i = 0; i < n; i++) {
//             vec[i[ = {capital[i], profits[i]};
//         }

//         sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b) {
//             if (a.first == b.first) {
//                 return a.second > b.second;
//             }
//             return a.first < b.first;
//         });
        
//         int totalProfit = 0;
//         for (int i = 0; i < k; i++) {
//             pair<int, int> temp = vec[i];
//             if (temp.first <= w) {
//                 w += temp.second;
//             } else {
//                 break;
//             }
//         }
//         return w;
//     }
// };