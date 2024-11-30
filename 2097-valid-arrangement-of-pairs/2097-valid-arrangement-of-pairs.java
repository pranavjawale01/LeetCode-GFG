class Solution {
    public int[][] validArrangement(int[][] pairs) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
        Map<Integer, Integer> indegree = new HashMap<>();
        Map<Integer, Integer> outdegree = new HashMap<>();
        for (int[] x : pairs) {
            mp.putIfAbsent(x[0], new ArrayList<>());
            mp.get(x[0]).add(x[1]);
            indegree.put(x[1], indegree.getOrDefault(x[1], 0) + 1);
            outdegree.put(x[0], outdegree.getOrDefault(x[0], 0) + 1);
        }
        int start = -1;
        for (Map.Entry<Integer, List<Integer>> x : mp.entrySet()) {
            int key = x.getKey();
            if (outdegree.getOrDefault(key, 0) - indegree.getOrDefault(key, 0) == 1) {
                start = key;
                break;
            }
        }
        if (start == -1) start = pairs[0][0];
        List<Integer> path = new ArrayList<>();
        Stack<Integer> st = new Stack<>();
        st.push(start);
        while (!st.isEmpty()) {
            int curr = st.peek();
            if (mp.containsKey(curr) && !mp.get(curr).isEmpty()) {
                int next = mp.get(curr).remove(mp.get(curr).size() - 1);
                st.push(next);
            } else {
                path.add(st.pop());
            }
        }
        Collections.reverse(path);
        int n = path.size();
        int[][] ans = new int[n - 1][2];
        for (int i = 0; i < n - 1; i++) {
            ans[i][0] = path.get(i);
            ans[i][1] = path.get(i + 1);
        }        
        return ans;
    }
}