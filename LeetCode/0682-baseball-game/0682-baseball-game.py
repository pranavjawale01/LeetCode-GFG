class Solution:
    def calPoints(self, operations: List[str]) -> int:
        score = []
        for op in operations:
            if op == "C":
                score.pop()
            elif op == "D":
                score.append(score[-1] * 2)
            elif op == "+":
                score.append(score[-1] + score[-2])
            else:
                score.append(int(op))
        return sum(score)