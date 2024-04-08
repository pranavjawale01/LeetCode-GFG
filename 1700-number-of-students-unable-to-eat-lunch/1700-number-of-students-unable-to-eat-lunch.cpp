class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int arr[2] = {0};
        for (int &nums : students) {
            if (nums == 1) {
                arr[1]++;
            }
        }
        arr[0] = n - arr[1];
        for (int i = 0; i < n; i++) {
            int sand = sandwiches[i];
            if (arr[sand] == 0) {
                return n - i;
            }
            arr[sand]--;
        }
        return 0;
    }
};