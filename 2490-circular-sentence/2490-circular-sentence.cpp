class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        
        if (sentence[0] != sentence[n - 1]) {
            return false;
        }
        
        stringstream ss(sentence);
        string curr, prev;
        
        while (ss >> curr) {
            if (!prev.empty()) {
                int k = prev.size();
                if (curr[0] != prev[k - 1]) {
                    return false;
                }
            }
            prev = curr;
        }
        
        return true;
    }
};