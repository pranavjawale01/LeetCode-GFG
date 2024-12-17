class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);
        for(char &ch : s) {
            count[ch - 'a']++;
        }

        priority_queue<char> pq;
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                pq.push('a' + i);
            }
        }

        string result;
        while(!pq.empty()) {
            char ch = pq.top();
            pq.pop();

            int freq = min(count[ch - 'a'], repeatLimit);
            result.append(freq, ch);
            count[ch - 'a'] -= freq;

            if (count[ch - 'a'] > 0 && !pq.empty()) {
                char nextChar = pq.top();
                pq.pop();

                result.push_back(nextChar);
                count[nextChar - 'a']--;

                if(count[nextChar - 'a'] > 0) {
                    pq.push(nextChar);
                }
                pq.push(ch);
            }
        }
        return result;
    }
};







// class Solution {
// public:
//     string repeatLimitedString(string s, int repeatLimit) {
//         vector<int> count(26, 0);
//         for(char &ch : s) {
//             count[ch - 'a']++;
//         }

//         string result;
//         int i = 25;
//         while(i >= 0) {
//             if(count[i] == 0) {
//                 i--;
//                 continue;
//             }

//             char ch  = 'a' + i;
//             int freq = min(count[i], repeatLimit);

//             result.append(freq, ch);
//             count[i] -= freq;

//             if(count[i] > 0) {
//                 int j = i - 1;
//                 while(j >= 0 && count[j] == 0) {
//                     j--;
//                 }

//                 if(j < 0) {
//                     break;
//                 }

//                 result.push_back('a' + j);
//                 count[j]--;
//             }
//         }
//         return result;
//     }
// };