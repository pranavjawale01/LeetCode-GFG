class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;
        int n = students.size();
        for (int i = 0; i < n; i++) {
            st.push(sandwiches[n - i - 1]);
            q.push(students[i]);
        }
        int lastServed = 0;
        while (!q.empty() && lastServed < q.size()) {
            if (st.top() == q.front()) {
                st.pop();
                q.pop();
                lastServed = 0;
            } else {
                q.push(q.front());
                q.pop();
                lastServed++;
            }
        }
        return q.size();
    }
};

// class Solution {
// public:
//     int countStudents(vector<int>& students, vector<int>& sandwiches) {
//         int n = students.size();
//         int arr[2] = {0};
//         for (int &nums : students) {
//             if (nums == 1) {
//                 arr[1]++;
//             }
//         }
//         arr[0] = n - arr[1];
//         for (int i = 0; i < n; i++) {
//             int sand = sandwiches[i];
//             if (arr[sand] == 0) {
//                 return n - i;
//             }
//             arr[sand]--;
//         }
//         return 0;
//     }
// };