class Solution {
    public void findSums(int[] candidates, int target, int start, List<List<Integer>> result, List<Integer> current) {
        if (target == 0) {
            result.add(new ArrayList<>(current));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] <= target) {
                current.add(candidates[i]);
                findSums(candidates, target - candidates[i], i + 1, result, current);
                current.remove(current.size() - 1);
            }
        }
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> current = new ArrayList<>();
        findSums(candidates, target, 0, result, current);
        return result;
    }
}