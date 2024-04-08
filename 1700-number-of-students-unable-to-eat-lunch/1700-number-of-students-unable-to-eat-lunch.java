class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int n = students.length;
        int[] arr = new int[2];
        for (int num : students) {
            if (num == 1) {
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
}