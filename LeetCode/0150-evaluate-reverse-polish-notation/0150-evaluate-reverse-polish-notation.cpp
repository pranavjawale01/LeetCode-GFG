class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        unordered_map<string, function<int (int, int)>> mp= {
            {"+", [](int a, int b) {return a + b; }},
            {"-", [](int a, int b) {return a - b; }},
            {"*", [](int a, int b) {return a * b; }},
            {"/", [](int a, int b) {return a / b; }},
        };
    
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int operator2 = stk.top();
                stk.pop();
                int operator1 =  stk.top();
                stk.pop();
                int result = mp[tokens[i]](operator1, operator2);                
                stk.push(result);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};

/*
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
    
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int operator2 = stk.top();
                stk.pop();
                int operator1 =  stk.top();
                stk.pop();

                int tempResult;
                if (tokens[i] == "+") {
                    tempResult = (operator1 + operator2);
                } else if(tokens[i] == "-") {
                    tempResult = (operator1 - operator2);
                } else if(tokens[i] == "*") {
                    tempResult = (operator1 * operator2);
                } else if(tokens[i] == "/") {
                    tempResult = (operator1 / operator2);
                }
                stk.push(tempResult);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
*/