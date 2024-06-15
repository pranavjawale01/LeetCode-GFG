class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;
        List<Pair<Integer, Integer>> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(new Pair<>(capital[i], profits[i]));
        }
        list.sort((a, b) -> a.getKey().equals(b.getKey()) ? b.getValue() - a.getValue() : a.getKey() - b.getKey());
        int i = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        while (k-- > 0) {
            while (i < n && list.get(i).getKey() <= w) {
                pq.add(list.get(i).getValue());
                i++;
            }
            if (pq.isEmpty()) {
                break;
            }
            w += pq.poll();
        }
        return w;
    }
}