class Solution {
    public int findTheWinner(int n, int k) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            q.offer(i+1);
        }
        while (q.size() > 1) {
            for (int i = 0; i < k - 1; i++) {
                q.add(q.poll());
            }
            q.poll();
        }
        return q.poll();
    }
}




// class Solution {
//     public int findTheWinner(int n, int k) {
//         List<Integer> arr = new ArrayList<>();
//         for (int i = 0; i < n; i++) {
//             arr.add(i+1);
//         }
//         int i = 0;
//         while (arr.size() > 1) {
//             i = (i + k - 1) % arr.size();
//             arr.remove(i);
//         }
//         return arr.get(0);
//     } 
// }