class Solution {
    public boolean canReach(int[] arr, int start) {
        Queue<Integer> q = new LinkedList<>();
        int n = arr.length;
        q.offer(start);
        while (!q.isEmpty()) {
            int curr = q.poll();
            if (arr[curr] == 0) {
                return true;
            }
            if (arr[curr] < 0) {
                continue;
            }
            int jump = arr[curr];
            arr[curr] = -arr[curr];
            if (curr + jump < n) {
                q.offer(curr + jump);
            }
            if (curr - jump >= 0) {
                q.offer(curr - jump);
            }
        }
        return false;
    }
}



// class Solution {
//     public boolean canReach(int[] arr, int start) {
//         if (start < 0 || start >= arr.length) {
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
//         return canReach(arr, start - jump) || canReach(arr, start + jump);
//     }
// }