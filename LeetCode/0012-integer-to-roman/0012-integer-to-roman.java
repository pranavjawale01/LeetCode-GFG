class Solution {
    public String intToRoman(int num) {
        int[] value = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        String[] roman = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        String result = "";
        for(int i=12;i>=0;i--)
        {
            while(num >= value[i])
            {
                result += roman[i];
                num -= value[i];
            }
        }
        return result;
    }
}