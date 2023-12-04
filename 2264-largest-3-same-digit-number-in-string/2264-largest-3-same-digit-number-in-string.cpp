class Solution {
public:
    string largestGoodInteger(string num) {
        string str = "";
        for (int i = 0; i < num.length() - 2; ++i) {
            string temp = num.substr(i, 3);
            if (temp[0] == temp[1] && temp[1] == temp[2]) {
                if (temp > str) {
                    str = temp;
                }
            }
        }
        return str;
    }
};