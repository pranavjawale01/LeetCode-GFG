class Solution:
    def gcd(self, a, b) -> int:
        while b != 0:
            a, b = b, a % b
        return a

    def fractionAddition(self, expression: str) -> str:
        nume, deno = 0, 1
        n = len(expression)
        i = 0
        
        while i < n:
            currNume, currDeno = 0, 0
            isNeg = False

            if expression[i] == '-' or expression[i] == '+':
                isNeg = expression[i] == '-'
                i += 1

            while i < n and expression[i].isdigit():
                currNume = currNume * 10 + int(expression[i])
                i += 1

            if isNeg:
                currNume *= -1

            i += 1

            while i < n and expression[i].isdigit():
                currDeno = currDeno * 10 + int(expression[i])
                i += 1

            nume = nume * currDeno + currNume * deno
            deno = deno * currDeno

            gcd = abs(self.gcd(nume, deno))
            nume //= gcd
            deno //= gcd

        return str(nume) + "/" + str(deno)