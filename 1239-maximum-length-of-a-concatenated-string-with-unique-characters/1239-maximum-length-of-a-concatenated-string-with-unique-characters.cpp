class Solution {
public:
    unordered_map<string, int> memory;

    bool hasDuplicate(string &s1, string &s2) {
        string temp = s1 + s2;
        unordered_set<char> charSet;
        for (char ch : temp) {
            if (charSet.count(ch) > 0) {
                return true;
            }
            charSet.insert(ch);
        }
        return false;
    }

    int recursive(vector<string>& arr, string temp, int i) {
        if (arr.size() <= i) {
            return temp.length();
        }
        if (memory.find(temp) != memory.end()) {
            return memory[temp];
        }
        int include = 0, exclude = 0;
        if (hasDuplicate(temp, arr[i])) {
            exclude = recursive(arr, temp, i + 1);
        } else {
            include = recursive(arr, temp + arr[i], i + 1);
            exclude = recursive(arr, temp, i + 1);
        }
        return memory[temp] = max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        string temp = "";
        memory.clear();
        return recursive(arr, temp, 0);
    }
};