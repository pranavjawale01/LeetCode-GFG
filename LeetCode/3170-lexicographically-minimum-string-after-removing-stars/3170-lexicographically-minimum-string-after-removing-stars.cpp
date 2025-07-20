class Solution {
public:
    struct Cmp {
        bool operator()(const pair<char, int> &a, const pair<char, int> &b) const {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Cmp> pq;
        int n = s.size();
        vector<int> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                auto p = pq.top();
                pq.pop();
                char ch = p.first;
                int  id = p.second;
                vis[id] = true;
            } else {
                pq.push({s[i], i});
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (!vis[i] && s[i] != '*') {
                ans += s[i];
            }
        }
        return ans;
    }
};