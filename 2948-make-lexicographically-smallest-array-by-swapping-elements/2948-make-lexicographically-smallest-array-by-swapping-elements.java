class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        int[] vec = nums.clone();
        Arrays.sort(vec);
        
        int groupNum = 0;
        Map<Integer, Integer> numToGroup = new HashMap<>();
        numToGroup.put(vec[0], groupNum);
        
        Map<Integer, LinkedList<Integer>> groupToList = new HashMap<>();
        groupToList.put(groupNum, new LinkedList<>());
        groupToList.get(groupNum).add(vec[0]);
        
        for (int i = 1; i < n; i++) {
            if (Math.abs(vec[i] - vec[i - 1]) > limit) {
                groupNum++;
            }
            numToGroup.put(vec[i], groupNum);
            groupToList.computeIfAbsent(groupNum, k -> new LinkedList<>()).add(vec[i]);
        }
        
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGroup.get(num);
            res[i] = groupToList.get(group).removeFirst();
        }
        
        return res;
    }
}