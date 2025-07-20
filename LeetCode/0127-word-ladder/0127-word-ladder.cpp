
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        int count = 1;
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string temp = q.front();
                q.pop();
                if (temp == endWord) {
                    return count;
                }
                dict.erase(temp);
                
                for (int j = 0; j < temp.size(); j++) {
                    char original_char = temp[j];
                    for (char k = 'a'; k <= 'z'; k++) {
                        temp[j] = k;
                        if (dict.find(temp) != dict.end()) {
                            q.push(temp);
                            dict.erase(temp);
                        }
                    }
                    temp[j] = original_char;
                }
            }
            count++;
        }
        
        return 0;
    }
};