class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] indegree = new int[numCourses];
        Map<Integer, List<Integer>> mp = new HashMap<>();
        
        for (int[] x : prerequisites) {
            if (!mp.containsKey(x[1])) {
                mp.put(x[1], new ArrayList<>());
            }
            mp.get(x[1]).add(x[0]);
            indegree[x[0]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        int count = 0;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.add(i);
                count++;
            }
        }
        
        while (!q.isEmpty()) {
            int curr = q.poll();
            if (mp.containsKey(curr)) {
                for (int x : mp.get(curr)) {
                    indegree[x]--;
                    if (indegree[x] == 0) {
                        q.add(x);
                        count++;
                    }
                }
            }
        }
        
        return count == numCourses;
    }
}