class Solution {
public:
    vector<int> getNSR(vector<int> &height) {
        stack<int> st;
        int n = height.size();
        vector<int> NSR(n);
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                NSR[i] = n;
            } else {
                while (!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    NSR[i] = n;
                } else {
                    NSR[i] = st.top();
                }
            }
            st.push(i);
        }
        return NSR;
    }
    vector<int> getNSL(vector<int> &height) {
        stack<int> st;
        int n = height.size();
        vector<int> NSL(n);
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                NSL[i] = -1;
            } else {
                while (!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    NSL[i] = -1;
                } else {
                    NSL[i] = st.top();
                }
            }
            st.push(i);
        }
        return NSL;
    }
    int findMaxArea(vector<int> &height) {
        vector<int> NSR = getNSR(height);
        vector<int> NSL = getNSL(height);
        int n = height.size();
        vector<int> width(n);
        for (int i = 0; i < n; i++) {
            width[i] = NSR[i] - NSL[i] - 1;
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int a = width[i] * height[i];
            maxArea = max(maxArea, a);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int m = matrix[0].size(), n = matrix.size();
        vector<int> height(m);
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
            maxArea = max(maxArea, findMaxArea(height));
        }
        return maxArea;
    }
};