class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int n = students.length;
        Queue<Integer> que = new LinkedList<>();
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            st.push(sandwiches[n - i - 1]);
            que.add(students[i]);
        }
        int lastServed = 0;
        while (!que.isEmpty() && lastServed < que.size()) {
            if (st.peek() == que.peek()) {
                st.pop();
                que.poll();
                lastServed = 0;
            } else {
                que.add(que.peek());
                que.poll();
                lastServed++;
            }
        }
        return que.size();
    }
}

// class Solution {
//     public int countStudents(int[] students, int[] sandwiches) {
//         int n = students.length;
//         int[] arr = new int[2];
//         for (int num : students) {
//             if (num == 1) {
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
// }