class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int ans = 0;
        int minEl = arrays.get(0).get(0);
        int maxEl = arrays.get(0).get(arrays.get(0).size() - 1);

        for (int i = 1; i < arrays.size(); ++i) {
            List<Integer> arr = arrays.get(i);
            int distMin = Math.abs(arr.get(0) - maxEl);
            int distMax = Math.abs(arr.get(arr.size() - 1) - minEl);
            
            ans = Math.max(ans, Math.max(distMin, distMax));

            minEl = Math.min(minEl, arr.get(0));
            maxEl = Math.max(maxEl, arr.get(arr.size() - 1));
        }

        return ans;
    }
}