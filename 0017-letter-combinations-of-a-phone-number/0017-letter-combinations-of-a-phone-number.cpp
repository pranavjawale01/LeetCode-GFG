class Solution {
public:
    void strCombinations(string digits, vector<string> &res, string &curStr, vector<string> &keypad, int index)
    {
        if(index== digits.size())
        {
            res.push_back(curStr);
            return;
        }
        string value = keypad[digits[index]-'0'];
        for(int i=0;i<value.size();i++)
        {
            curStr.push_back(value[i]);
            strCombinations(digits,res,curStr,keypad,index+1);
            curStr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        {
            return {};
        }
        vector<string> res;
        vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string curStr;
        strCombinations(digits,res,curStr,keypad,0);
        return res;
    }
};