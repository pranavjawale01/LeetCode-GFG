class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        string ans = "";
        while (!pq.empty()) {
            auto [freq, var] = pq.top();
            pq.pop();
            if (ans.size() >= 2 && ans.back() == var && ans[ans.size() - 2] == var) {
                if (pq.empty()) {
                    break;
                }
                auto [freq1, var1] = pq.top();
                pq.pop();
                ans.push_back(var1);
                freq1--;
                if (freq1 > 0) pq.push({freq1, var1});
            } else {
                freq--;
                ans.push_back(var);
            }
            if (freq > 0) pq.push({freq, var});
        }
        return ans;
    }
};