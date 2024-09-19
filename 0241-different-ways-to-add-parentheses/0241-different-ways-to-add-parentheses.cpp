class Solution {
public:
    vector<int> solve(string s) {
        vector<int> arr;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left  = solve(s.substr(0, i));
                vector<int> right = solve(s.substr(i+1));
                for (int &x : left) {
                    for (int &y : right) {
                        if (s[i] == '+') {
                            arr.push_back(x + y);
                        } else if(s[i] == '-') {
                            arr.push_back(x - y);
                        } else {
                            arr.push_back(x * y);
                        }
                    }
                }
            }
        }
        if (arr.empty()) {
            arr.push_back(stoi(s));
        }
        return arr;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};