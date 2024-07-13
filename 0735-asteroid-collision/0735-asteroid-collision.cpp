class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for (int x : asteroids) {
            if (x > 0) {
                st.push(x);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(x)) {
                    st.pop();
                }
                if (st.empty() || st.top() < 0) {
                    ans.push_back(x);
                } else if (st.top() == abs(x)) {
                    st.pop();
                }
            }
        }

        int n = ans.size();
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin() + n, ans.end());

        return ans;
    }
};