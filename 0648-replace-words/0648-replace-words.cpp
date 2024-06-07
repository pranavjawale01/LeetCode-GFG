class Solution {
public:
    string findWord(string &word, unordered_set<string> &st) {
        for (int i = 1; i < word.length(); i++) {
            string temp = word.substr(0, i);
            if (st.find(temp) != st.end()) {
                return temp;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word;
        string result;
        while (getline(ss, word, ' ')) {
            result += findWord(word, st) + " ";
        }
        result.pop_back();
        return result;
    }
};