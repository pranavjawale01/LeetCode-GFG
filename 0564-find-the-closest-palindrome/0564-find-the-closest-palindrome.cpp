class Solution {
public:
    long solve(long firstHalf, bool isEven) {
        long resultNum = firstHalf;
        if (!isEven) {
            firstHalf /= 10;
        }
        while (firstHalf > 0) {
            int digit = firstHalf % 10;
            resultNum = resultNum * 10 + digit;
            firstHalf /= 10;
        }
        return resultNum;
    }

    string nearestPalindromic(string n) {
        int l = n.length();
        int mid = l / 2;
        long firstHalfLen = (l % 2 == 0) ? mid : (mid + 1);
        long firstHalf = stol(n.substr(0, firstHalfLen));
        vector<long> possibleResults;
        possibleResults.push_back(solve(firstHalf, l % 2 == 0));
        possibleResults.push_back(solve(firstHalf + 1, l % 2 == 0));
        possibleResults.push_back(solve(firstHalf - 1, l % 2 == 0));
        possibleResults.push_back((long)pow(10, l - 1) - 1);
        possibleResults.push_back((long)pow(10, l) + 1);

        long diff = LONG_MAX;
        long result = -1;
        long originalNum = stol(n);
        
        for (long num : possibleResults) {
            if (num == originalNum) {
                continue;
            }
            if (abs(num - originalNum) < diff) {
                diff = abs(num - originalNum);
                result = num;
            } else if (abs(num - originalNum) == diff) {
                result = min(result, num);
            }
        }
        return to_string(result);
    }
};







// class Solution {
// public:
//     string nearestPalindromic(string n) {
//         int len = n.length();
//         long long prefix = stoll(n.substr(0, (len + 1) / 2));
//         vector<long long> candidates;

//         for (int i = -1; i <= 1; ++i) {
//             string p = to_string(prefix + i);
//             string pal = p + string(p.rbegin() + (len & 1), p.rend());
//             candidates.push_back(stoll(pal));
//         }

//         candidates.push_back((long long)pow(10, len - 1) - 1);
//         candidates.push_back((long long)pow(10, len) + 1);

//         long long minDiff = LLONG_MAX, result = 0, num = stoll(n);
//         for (long long candidate : candidates) {
//             if (candidate == num) continue;
//             long long diff = abs(candidate - num);
//             if (diff < minDiff || (diff == minDiff && candidate < result)) {
//                 minDiff = diff;
//                 result = candidate;
//             }
//         }

//         return to_string(result);
//     }
// };