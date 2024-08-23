class Solution {
public:
    string fractionAddition(string expression) {
        int nume = 0;
        int deno = 1;
        int i = 0;
        int n = expression.length();
        
        while (i < n) {
            int currNume = 0;
            int currDeno = 0;
            bool isNeg = false;
            
            if (expression[i] == '-' || expression[i] == '+') {
                isNeg = expression[i] == '-';
                i++;
            }
            
            while (i < n && isdigit(expression[i])) {
                currNume = currNume * 10 + (expression[i] - '0');
                i++;
            }
            
            if (isNeg) {
                currNume = -currNume;
            }
            
            i++;
            
            while (i < n && isdigit(expression[i])) {
                currDeno = currDeno * 10 + (expression[i] - '0');
                i++;
            }
            
            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
            
            int GCD = abs(__gcd(nume, deno));
            nume /= GCD;
            deno /= GCD;
        }
        
        return to_string(nume) + "/" + to_string(deno);
    }
};