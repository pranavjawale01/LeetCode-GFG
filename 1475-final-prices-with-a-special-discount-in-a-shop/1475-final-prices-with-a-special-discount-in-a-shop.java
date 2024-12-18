class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && prices[i] <= prices[st.peek()]) {
                prices[st.peek()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
}




// class Solution {
//     public int[] finalPrices(int[] prices) {
//         int n = prices.length;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (prices[i] >= prices[j]) {
//                     prices[i] -= prices[j];
//                     break;
//                 }
//             }
//         }
//         return prices;
//     }
// }