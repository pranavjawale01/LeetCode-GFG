class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int start = 0, end = 0;
        for (int i=0;i<s.length();++i) 
        {
            if (s[i]==' ') 
            {
                for (int j=end-1;j>=start;--j) 
                {
                    result += s[j];
                }
                result += ' ';
                start = i+1;
            }
            end = i+1;
        }
        for (int j=end-1;j>=start;--j) 
        {
            result += s[j];
        }
        return result;
    }
};