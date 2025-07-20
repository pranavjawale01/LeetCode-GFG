class Solution {
public:    
    bool checkSubstring(unordered_map<string, int> wordCount, string s, int wordLen) 
    {
        for(int j=0; j<s.size(); j+=wordLen)
        {
            string w = s.substr(j, wordLen);
            if(wordCount.find(w) != wordCount.end()) 
            {
                if(--wordCount[w] == -1) 
                {
                    return false;
                }
            } 
            else
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordLen = words[0].size();
        int sLen = s.size();
        int wordsWindow = words.size() * wordLen;
        
        unordered_map<string, int> wordCount;
        for(int i=0; i<words.size(); i++) 
        {
            wordCount[words[i]]++;
        }
        
        int i = 0;
        while(i + wordsWindow <= sLen) 
        {
            if(checkSubstring(wordCount, s.substr(i, wordsWindow), wordLen)) 
            {
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};




/*
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty() || s.empty()) 
        {
            return result;
        }        
        int wordLen = words[0].length();
        int totalLen = wordLen * words.size();
        unordered_map<string, int> wordCount;        
        for(const string& word : words) 
        {
            wordCount[word]++;
        }        
        for(int i = 0; i <= s.length() - totalLen; ++i) 
        {
            unordered_map<string, int> seen;
            int j;
            for (j = 0; j < words.size(); ++j)
            {
                if(i + j * wordLen + wordLen <= s.length()) 
                {
                    string word = s.substr(i + j * wordLen, wordLen);
                    if(wordCount.find(word) != wordCount.end()) 
                    {
                        seen[word]++;
                        if(seen[word] > wordCount[word]) 
                        {
                            break;
                        }
                    } 
                    else 
                    {
                        break;
                    }
                }
                else 
                {
                    break;
                }
            }
            if(j == words.size()) 
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
*/