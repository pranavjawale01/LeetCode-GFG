class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<int[]>pq = new PriorityQueue<>((a,b)->{
            if(a[0] != b[0]){
                return a[0] - b[0];
            }else {
                return a[1] - b[1];
            }
        });

        for(int i = 0; i < nums.length; i++){
            pq.add(new int[]{nums[i], i});
        }

        while(k > 0){
            int[] minEleObj = pq.poll();
            int ind = minEleObj[1];
            int val = minEleObj[0];

            nums[ind] = nums[ind] * multiplier;
            pq.add(new int[]{nums[ind], ind});
            k--;
        }

        return nums;
    }
}





// class Solution {
//     public int[] getFinalState(int[] nums, int k, int multiplier) {
//         for (int i = 0; i < k; ++i) {
//             int minIndex = 0;
//             for (int j = 1; j < nums.length; j++) {
//                 if (nums[j] < nums[minIndex]) {
//                     minIndex = j;
//                 }
//             }
//             nums[minIndex] *= multiplier;
//         }
//         return nums;
//     }
// }