class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length , ans = 0, i = 0;
        Stack<Integer> st = new Stack<>();
        st.push(0);
        while (i < n) {
            while (!st.isEmpty() && heights[st.peek()] > heights[i]) {
                int index = st.peek();
                st.pop();
                int height = heights[index];
                
                if (st.isEmpty()) {
                    ans = Math.max(ans , height * i);
                } else {
                    int len = i - st.peek() - 1;
                    ans = Math.max(ans , height * len);
                }
            }
            st.push(i);
            i++;
        }
        while (!st.isEmpty()) {
            int index = st.peek();
            st.pop();
            int height = heights[index];
            
            if (st.isEmpty()) {
                ans = Math.max(ans , height * i);
            } else {
                int len = i - st.peek() - 1;
                ans = Math.max(ans , height * len);
            }
        }
        
        return ans;
    }
}