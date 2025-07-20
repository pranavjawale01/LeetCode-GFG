class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(candidates);
        findCombination(candidates, target, 0, new ArrayList<>(), result);
        return result;
    }
    
    public void findCombination(int[] candidates, int target, int start, List<Integer> current, List<List<Integer>> result) {
        if (target == 0) {
            result.add(new ArrayList<>(current));
            return;
        }
        
        for (int i = start; i < candidates.length && candidates[i] <= target; i++) {
            current.add(candidates[i]);
            findCombination(candidates, target - candidates[i], i, current, result);
            current.remove(Integer.valueOf(candidates[i]));
        }
    }
}