class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        List<Integer> idx = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            idx.add(i);
        }
        Collections.sort(idx, (id1, id2) -> Integer.compare(positions[id1], positions[id2]));
        Stack<Integer> st = new Stack<>();
        for (int id : idx) {
            if (directions.charAt(id) == 'R') {
                st.push(id);
            } else {
                while (!st.isEmpty() && healths[id] > 0) {
                    if (healths[id] > healths[st.peek()]) {
                        healths[id]--;
                        healths[st.pop()] = 0;
                    } else if (healths[id] < healths[st.peek()]) {
                        healths[id] = 0;
                        healths[st.peek()]--;
                    } else {
                        healths[id] = 0;
                        healths[st.pop()] = 0;
                    }
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.add(healths[i]);
            }
        }
        return ans;
    }
}