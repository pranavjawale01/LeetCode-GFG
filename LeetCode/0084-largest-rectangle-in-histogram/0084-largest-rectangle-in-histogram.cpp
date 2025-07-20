class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0, i = 0;
        stack<int> st;
        st.push(0);

        while (i < n) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int index = st.top();
                st.pop();
                int height = heights[index];
                
                if (st.empty()) {
                    ans = max(ans, height * i);
                } else {
                    int len = i - st.top() - 1;
                    ans = max(ans, height * len);
                }
            }
            st.push(i);
            i++;
        }

        while (!st.empty()) {
            int index = st.top();
            st.pop();
            int height = heights[index];

            if (st.empty()) {
                ans = max(ans, height * i);
            } else {
                int len = i - st.top() - 1;
                ans = max(ans, height * len);
            }
        }

        return ans;
    }
};