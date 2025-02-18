class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";
        int counter = 1;
        stack<char> st;
        for (int i = 0; i <= n; i++) {
            st.push(counter + '0');
            counter++;
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    ans += st.top();
                    st.pop();
                }
            }
        }
        return ans;
    }
};