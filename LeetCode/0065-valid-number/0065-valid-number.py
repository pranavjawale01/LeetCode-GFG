class Solution:
    def isNumber(self, s: str) -> bool:
        result, dFlag, eFlag = False, False, False
        i = 0

        if i < len(s) and (s[i] == '-' or s[i] == '+'):
            i += 1

        while i < len(s) and s[i].isdigit():
            result = True
            i += 1

        if i < len(s) and s[i] == '.':
            i += 1
            dFlag = True

        while i < len(s) and s[i].isdigit():
            result = True
            i += 1

        if i < len(s) and (s[i] == 'e' or s[i] == 'E') and result and not eFlag:
            i += 1
            eFlag = True
            result = False
            if i < len(s) and (s[i] == '-' or s[i] == '+'):
                i += 1

        while i < len(s) and s[i].isdigit():
            result = True
            i += 1

        while i < len(s) and s[i].isspace():
            i += 1

        return result and i == len(s)

# class Solution:
#     def isNumber(self, s: str) -> bool:
#         # Define a DFA
#         state = [{},
#             {'blank': 1, 'sign': 2, 'digit': 3, '.': 4},
#             {'digit': 3, '.': 4},
#             {'digit': 3, '.': 5, 'e': 6, 'blank': 9},
#             {'digit': 5},
#             {'digit': 5, 'e': 6, 'blank': 9},
#             {'sign': 7, 'digit': 8},
#             {'digit': 8},
#             {'digit': 8, 'blank': 9},
#             {'blank': 9}]
#         currentState = 1
#         for c in s:
#             if c >= '0' and c <= '9':
#                 c = 'digit'
#             if c == ' ':
#                 c = 'blank'
#             if c in ['+', '-']:
#                 c = 'sign'
#             if c not in state[currentState].keys():
#                 return False
#             currentState = state[currentState][c]
#         if currentState not in [3, 5, 8, 9]:
#             return False
#         return True