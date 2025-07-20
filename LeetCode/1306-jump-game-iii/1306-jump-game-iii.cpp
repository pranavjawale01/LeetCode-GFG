class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        int n = arr.size();
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (arr[curr] == 0) {
                return true;
            }
            if (arr[curr] < 0) {
                continue;
            }
            int jump = arr[curr];
            arr[curr] = -arr[curr];
            if (curr + jump < n) {
                q.push(curr + jump);
            }
            if (curr - jump >= 0) {
                q.push(curr - jump);
            }
        }
        return false;
    }
};


// class Solution {
// public:
//     bool canReach(vector<int>& arr, int start) {
//         if (start < 0 || start >= arr.size()) {
//             return false;
//         }
//         if (arr[start] < 0) {
//             return false;
//         }
//         if (arr[start] == 0) {
//             return true;
//         }
//         int jump = arr[start];
//         arr[start] = -arr[start];
//         bool can_reach_left = canReach(arr, start - jump);
//         bool can_reach_right = canReach(arr, start + jump);
//         return can_reach_left || can_reach_right;
//     }
// };
