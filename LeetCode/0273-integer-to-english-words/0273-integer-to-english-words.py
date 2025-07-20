class Solution:
    def __init__(self):
        self.ten = {0: "", 1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five", 6: "Six", 7: "Seven", 8: "Eight", 9: "Nine"}
        self.twenty = {10: "Ten", 11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen", 15: "Fifteen", 16: "Sixteen", 17: "Seventeen", 18: "Eighteen", 19: "Nineteen"}
        self.hundred = {2: "Twenty", 3: "Thirty", 4: "Forty", 5: "Fifty", 6: "Sixty", 7: "Seventy", 8: "Eighty", 9: "Ninety"}

    def solve(self, num: int) -> str:
        if num < 10:
            return self.ten[num]
        if num < 20:
            return self.twenty[num]
        if num < 100:
            return self.hundred[num // 10] + (" " + self.ten[num % 10] if num % 10 != 0 else "")
        if num < 1000:
            return self.ten[num // 100] + " Hundred" + (" " + self.solve(num % 100) if num % 100 != 0 else "")
        if num < 1000000:
            return self.solve(num // 1000) + " Thousand" + (" " + self.solve(num % 1000) if num % 1000 != 0 else "")
        if num < 1000000000:
            return self.solve(num // 1000000) + " Million" + (" " + self.solve(num % 1000000) if num % 1000000 != 0 else "")
        return self.solve(num // 1000000000) + " Billion" + (" " + self.solve(num % 1000000000) if num % 1000000000 != 0 else "")

    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        return self.solve(num)