class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] visited = new boolean[n];
        visited[0] = true;
        Queue<Integer> q = new LinkedList<>();
        for (int room : rooms.get(0)) {
            q.offer(room);
        }
        while (!q.isEmpty()) {
            int temp = q.poll();
            visited[temp] = true; 
            for (int room : rooms.get(temp)) {
                if (visited[room] == false) {
                    q.offer(room);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }
}


// class Solution {
//     public void solve(List<List<Integer>> rooms, boolean[] visited, int i) {
//         if (visited[i] == true) {
//             return;
//         }
//         visited[i] = true;
//         for (int room : rooms.get(i)) {
//             solve(rooms, visited, room);
//         }
//     }
//     public boolean canVisitAllRooms(List<List<Integer>> rooms) {
//         int n = rooms.size();
//         boolean[] visited = new boolean[n];
//         visited[0] = true;
//         for (int room : rooms.get(0)) {
//             solve(rooms, visited, room);
//         }
//         for (int i = 0; i < n; i++) {
//             if (visited[i] == false) {
//                 return false;
//             }
//         }
//         return true;
//     }
// }