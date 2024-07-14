class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> st;
        int n = formula.size();
        int i = 0;
        st.push(unordered_map<string, int>());
        
        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;
                int mul = 0;
                while (i < n && isdigit(formula[i])) {
                    mul = mul * 10 + (formula[i] - '0');
                    i++;
                }
                if (mul == 0) mul = 1;
                
                for (auto &x : curr) {
                    curr[x.first] *= mul;
                }
                
                for (auto &x : curr) {
                    st.top()[x.first] += x.second;
                }
            } else {
                string currElement;
                currElement += formula[i++];
                while (i < n && islower(formula[i])) {
                    currElement += formula[i++];
                }
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                if (count == 0) count = 1;
                st.top()[currElement] += count;
            }
        }
        
        string ans = "";
        map<string, int> mp(st.top().begin(), st.top().end());
        for (auto &x : mp) {
            ans += x.first;
            if (x.second > 1) {
                ans += to_string(x.second);
            }
        }
        return ans;
    }
};