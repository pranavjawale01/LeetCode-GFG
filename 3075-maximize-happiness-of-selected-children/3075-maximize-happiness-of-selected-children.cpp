class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        for (int x : happiness) {
            pq.push(x);
        }
        long long sum = 0;
        int i = 0;
        while (k--) {
            if (pq.top() - i <= 0) {
                return sum;
            }
            sum += pq.top() - i;
            pq.pop();
            i++;
        }
        return sum;
    }
};


// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& happiness, int k) {
//         sort(happiness.begin(), happiness.end(), greater<int>());
//         long long sum = 0;
//         for (int i = 0; i < k; i++) {
//             if (happiness[i] - i > 0) {
//                 sum += happiness[i] - i;
//             } else {
//                 return sum;
//             }
//         }
//         return sum;
//     }
// };