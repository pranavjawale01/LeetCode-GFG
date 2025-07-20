class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }
        sort(vec.begin(), vec.end());
        sort(worker.begin(), worker.end());
        int totalProfit = 0;
        int j = 0;
        int maxProfit = 0;
        for (int i = 0; i < m; i++) {
            while (j < n && worker[i] >= vec[j].first) {
                maxProfit = max(maxProfit, vec[j].second);
                j++;
            }
            totalProfit += maxProfit;
        }
        return totalProfit;
    }
};



// class Solution {
// public:
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//         int n = profit.size();
//         int m = worker.size();
//         vector<pair<int, int>> vec;
//         for (int i = 0; i < n; i++) {
//             vec.push_back({difficulty[i], profit[i]});
//         }
//         sort(vec.begin(), vec.end());
//         for (int i = 1; i < vec.size(); i++) {
//             vec[i].second = max(vec[i].second, vec[i-1].second);
//         }
//         int totalProfit = 0;
//         for (int i = 0; i < m; i++) {
//             int level = worker[i];
//             int l = 0, r = vec.size() - 1;
//             int maxProfit = 0;
//             while (l <= r) {
//                 int mid = l + (r - l) / 2;
//                 if (vec[mid].first <= level) {
//                     maxProfit = max(maxProfit, vec[mid].second);
//                     l = mid + 1;
//                 } else {
//                     r = mid - 1;
//                 }
//             }
//             totalProfit += maxProfit;
//         }
//         return totalProfit;
//     }
// };




// class Solution {
// public:
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//         priority_queue<pair<int, int>> pq;
//         int n = profit.size();
//         int m = worker.size();
//         for (int i = 0; i < n; i++) {
//             pq.push({profit[i], difficulty[i]});
//         }
//         sort(worker.begin(), worker.end(), greater<int>());
//         int totalProfit = 0;
//         int i = 0;
//         while (!pq.empty() && i < m) {
//             if (pq.top().second > worker[i]) {
//                 pq.pop();
//             } else {
//                 totalProfit += pq.top().first;
//                 i++;
//             }
//         }
//         return totalProfit;
//     }
// };