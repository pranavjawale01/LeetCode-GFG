class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        vector<long long> candidates;

        for (int i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string pal = p + string(p.rbegin() + (len & 1), p.rend());
            candidates.push_back(stoll(pal));
        }

        candidates.push_back((long long)pow(10, len - 1) - 1);
        candidates.push_back((long long)pow(10, len) + 1);

        long long minDiff = LLONG_MAX, result = 0, num = stoll(n);
        for (long long candidate : candidates) {
            if (candidate == num) continue;
            long long diff = abs(candidate - num);
            if (diff < minDiff || (diff == minDiff && candidate < result)) {
                minDiff = diff;
                result = candidate;
            }
        }

        return to_string(result);
    }
};