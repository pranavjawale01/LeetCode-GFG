class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
        int[] indegree = new int[numCourses];
        
        for (int i = 0; i < numCourses; i++) {
            mp.put(i, new ArrayList<>());
        }
        
        for (int[] x : prerequisites) {
            mp.get(x[1]).add(x[0]);
            indegree[x[0]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        int count = 0;
        int[] ans = new int[numCourses];
        
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
                ans[count] = i;
                count++;
            }
        }
        
        while (!q.isEmpty()) {
            int x = q.poll();
            for (int v : mp.get(x)) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.offer(v);
                    ans[count] = v;
                    count++;
                }
            }
        }
        
        if (count == numCourses) {
            return ans;
        }
        
        return new int[0];
    }
}