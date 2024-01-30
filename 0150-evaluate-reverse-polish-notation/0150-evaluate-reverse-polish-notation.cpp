class Solution {
public:
    int evaluate(string op, int operand1, int operand2) {
        if (op == "+") {
            return operand1 + operand2;
        } else if (op == "-") {
            return operand1 - operand2;
        } else if (op == "*") {
            return operand1 * operand2;
        } else if (op == "/") {
            return operand1 / operand2;
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            string token = tokens[i];

            try {
                int num = stoi(token);
                stk.push(num);
            } catch (const invalid_argument& e) {
                int operand2 = stk.top();
                stk.pop();
                int operand1 = stk.top();
                stk.pop();
                int result = evaluate(token, operand1, operand2);
                stk.push(result);
            }
        }

        return stk.top();
    }
};