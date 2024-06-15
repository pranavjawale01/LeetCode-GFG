class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        
        int[] heights = new int[envelopes.length];
        for (int i = 0; i < envelopes.length; i++) {
            heights[i] = envelopes[i][1];
        }

        List<Integer> lis = new ArrayList<>();
        for (int height : heights) {
            int pos = binarySearch(lis, height);
            if (pos == lis.size()) {
                lis.add(height);
            } else {
                lis.set(pos, height);
            }
        }

        return lis.size();
    }

    private int binarySearch(List<Integer> lis, int target) {
        int left = 0, right = lis.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (lis.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}