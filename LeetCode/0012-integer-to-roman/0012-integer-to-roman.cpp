class Solution {
public:
    string intToRoman(int num) {
        vector<int> value;
        value = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> roman;
        roman = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string res="";
        for(int i=12;i>=0;i--)
        {
            while(num>=value[i])
            {
                res.append(roman[i]);
                num-=value[i];
            }
        }
        return res;
    }
};   