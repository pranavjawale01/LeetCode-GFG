class Solution {
    public List<String> letterCombinations(String digits) {
        String keypad[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        List<String> res = new ArrayList<String>();
        if(digits.length()==0)
        {
            return res;
        }
        res.add("");
        for(int i=0;i<digits.length();i++)
        {
            res = strCombination(keypad[digits.charAt(i)-'0'],res);
        }
        return res;
    }
    public static List<String> strCombination(String digits,List<String> curStr)
    {
        List<String> res = new ArrayList<String>();
        for(int i=0;i<digits.length();i++)
        {
            for(String x : curStr)
            {
                res.add(x+digits.charAt(i));
            }
        }
        return res;
    }
}