class Solution:
    def countOfAtoms(self, formula: str) -> str:
        stack = []
        n = len(formula)
        i = 0
        stack.append(collections.defaultdict(int))
        
        while i < n:
            if formula[i] == '(':
                stack.append(collections.defaultdict(int))
                i += 1
            elif formula[i] == ')':
                curr = stack.pop()
                i += 1
                mul = 0
                while i < n and formula[i].isdigit():
                    mul = mul * 10 + int(formula[i])
                    i += 1
                if mul == 0:
                    mul = 1
                
                for elem, cnt in curr.items():
                    curr[elem] *= mul
                
                for elem, cnt in curr.items():
                    stack[-1][elem] += cnt
            else:
                curr_element = formula[i]
                i += 1
                while i < n and formula[i].islower():
                    curr_element += formula[i]
                    i += 1
                count = 0
                while i < n and formula[i].isdigit():
                    count = count * 10 + int(formula[i])
                    i += 1
                if count == 0:
                    count = 1
                stack[-1][curr_element] += count
        
        ans = ""
        sorted_elements = sorted(stack[-1].items())
        for elem, cnt in sorted_elements:
            ans += elem
            if cnt > 1:
                ans += str(cnt)
        
        return ans