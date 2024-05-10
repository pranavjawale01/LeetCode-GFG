class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float, pair<int, int>>> pq;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    pq.push({(float)arr[i] / (float)arr[j], {arr[i], arr[j]}});
                }
            }
        }
        while (k-- > 1) {
            pq.pop();
        }
        return {pq.top().second.second, pq.top().second.first};
    }
};