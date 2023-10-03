class Solution {
    public int numIdenticalPairs(int[] nums) {
        int result=0, count[] = new int[101];
        for(int x: nums)
        {
            result += count[x]++;
        }
        return result;
    }
}