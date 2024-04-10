class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        int n = deck.size();
        sort(deck.begin(), deck.end());
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        vector<int> ans(n ,0);
        for (int i = 0; i < n; i++) {
            int idx = q.front();
            q.pop();
            ans[idx] = deck[i];
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> deckRevealedIncreasing(vector<int>& deck) {
//         int n = deck.size();
//         sort(deck.begin(), deck.end());
//         vector<int> ans(n , 0);
//         bool skip = false;
//         int i = 0, j = 0;
//         while (i < n) {
//             if (ans[j] == 0) {
//                 if (skip == false) {
//                     ans[j] = deck[i];
//                     i++;
//                 }
//                 skip = !skip;
//             }
//             j = (j + 1) % n;
//         }
//         return ans;
//     }
// };