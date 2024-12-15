class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        double ans = 1.0;
        unordered_map<string, vector<pair<string, double>>> mp1, mp2;
        int n = rates1.size(), m = rates2.size();
        for (int i = 0; i < n; i++) {
            mp1[pairs1[i][0]].push_back({pairs1[i][1], rates1[i]});
            mp1[pairs1[i][1]].push_back({pairs1[i][0], 1.0/rates1[i]});
        }
        for (int i = 0; i < m; i++) {
            mp2[pairs2[i][0]].push_back({pairs2[i][1], rates2[i]});
            mp2[pairs2[i][1]].push_back({pairs2[i][0], 1.0/rates2[i]});
        }
        function<unordered_map<string, double>(unordered_map<string, vector<pair<string, double>>>&, string&)> solve = [&](unordered_map<string, vector<pair<string, double>>> &mp, string &st) {
            unordered_map<string, double> maxAmt;
            maxAmt[st] = 1.0;
            queue<string> q;
            q.push(st);
            while (!q.empty()) {
                string curr = q.front();
                q.pop();
                double currAmt = maxAmt[curr];
                for (auto& x : mp[curr]) {
                    string ne = x.first;
                    double rt = x.second;
                    double amt = currAmt * rt;
                    if (amt > maxAmt[ne]) {
                        maxAmt[ne] = amt;
                        q.push(ne);
                    }
                }
            }
            return maxAmt;
        };
        unordered_map<string, double> d1 = solve(mp1, initialCurrency);
        for (auto &x : d1) {
            string currency = x.first;
            unordered_map<string, double> d2 = solve(mp2, currency);
            if (d2.count(initialCurrency)) {
                ans = max(ans, x.second * d2[initialCurrency]);
            }
        }
        return ans;
    }
};