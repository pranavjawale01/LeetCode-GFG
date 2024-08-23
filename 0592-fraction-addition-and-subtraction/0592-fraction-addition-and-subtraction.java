class Solution {
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public String fractionAddition(String expression) {
        int nume = 0;
        int deno = 1;
        int n = expression.length();
        int i = 0;

        while (i < n) {
            int currNume = 0;
            int currDeno = 0;
            boolean isNeg = false;

            if (expression.charAt(i) == '-' || expression.charAt(i) == '+') {
                isNeg = expression.charAt(i) == '-';
                i++;
            }

            while (i < n && Character.isDigit(expression.charAt(i))) {
                currNume = currNume * 10 + (expression.charAt(i) - '0');
                i++;
            }

            if (isNeg) {
                currNume *= -1;
            }

            i++;

            while (i < n && Character.isDigit(expression.charAt(i))) {
                currDeno = currDeno * 10 + (expression.charAt(i) - '0');
                i++;
            }

            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;

            int GCD = Math.abs(gcd(nume, deno));
            nume /= GCD;
            deno /= GCD;
        }

        return Integer.toString(nume) + "/" + Integer.toString(deno);
    }
}