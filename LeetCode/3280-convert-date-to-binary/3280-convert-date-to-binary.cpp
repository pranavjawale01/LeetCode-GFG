class Solution {
public:
    string intToBinary(int n) {
        string ans = "";
        bool leadingZero = true;
        
        for (int i = 31; i >= 0; i--) {
            if (n & (1 << i)) {
                ans.push_back('1');
                leadingZero = false;
            } else if (!leadingZero) {
                ans.push_back('0');
            }
        }
        return ans.empty() ? "0" : ans;
    }
    string convertDateToBinary(string date) {
        string yearStr = date.substr(0, 4);
        string monthStr = date.substr(5, 2);
        string dayStr = date.substr(8, 2);

        int yearInt = stoi(yearStr);
        int monthInt = stoi(monthStr);
        int dayInt = stoi(dayStr);

        string yearBinary = intToBinary(yearInt);
        string monthBinary = intToBinary(monthInt);
        string dayBinary = intToBinary(dayInt);

        return yearBinary + "-" + monthBinary + "-" + dayBinary;
    }
};