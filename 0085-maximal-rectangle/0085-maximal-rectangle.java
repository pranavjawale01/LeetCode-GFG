class Solution {
    public int[] getNSR(int[] height) {
        Stack<Integer> st = new Stack<>();
        int n = height.length;
        int[] NSR = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                NSR[i] = n;
            } else {
                while (!st.empty() && height[st.peek()] >= height[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    NSR[i] = n;
                } else {
                    NSR[i] = st.peek();
                }
            }
            st.push(i);
        }
        return NSR;
    }

    public int[] getNSL(int[] height) {
        Stack<Integer> st = new Stack<>();
        int n = height.length;
        int[] NSL = new int[n];
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                NSL[i] = -1;
            } else {
                while (!st.empty() && height[st.peek()] >= height[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    NSL[i] = -1;
                } else {
                    NSL[i] = st.peek();
                }
            }
            st.push(i);
        }
        return NSL;
    }

    public int findMaxArea(int[] height) {
        int[] NSR = getNSR(height);
        int[] NSL = getNSL(height);
        int n = height.length;
        int[] width = new int[n];
        for (int i = 0; i < n; i++) {
            width[i] = NSR[i] - NSL[i] - 1;
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int a = width[i] * height[i];
            maxArea = Math.max(maxArea, a);
        }
        return maxArea;
    }

    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) {
            return 0;
        }
        int m = matrix[0].length, n = matrix.length;
        int[] height = new int[m];
        for (int i = 0; i < m; i++) {
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }
        int maxArea = findMaxArea(height);
        for (int row = 1; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (matrix[row][col] == '0') {
                    height[col] = 0;
                } else {
                    height[col] += 1;
                }
            }
            maxArea = Math.max(maxArea, findMaxArea(height));
        }
        return maxArea;
    }
}