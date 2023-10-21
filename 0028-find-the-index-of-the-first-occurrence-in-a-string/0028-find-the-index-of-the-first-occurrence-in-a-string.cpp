class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0)
            return 0;
        if(haystack.length()==0)
            return -1;
        for(int i=0;i<haystack.length();i++)
        {
            if(needle.length()+i > haystack.length())
                break;
            for(int j=0;j<needle.length();j++)
            {
                if(haystack[i+j] != needle[j])
                    break;
                if(needle.length()-1 == j)
                    return i;
            }
        }
        return -1;
    }
};