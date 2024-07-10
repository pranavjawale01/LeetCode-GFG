class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (auto x : logs) {
            if (x == "../") {
                depth = max(0, depth - 1);
            } else if (x == "./") {
                continue;
            } else {
                depth++;
            }
        }
        return depth;
    }
};