class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        mp = {0 : -1}
        mask = 0
        ans = 0

        for i in range(len(s)):
            if s[i] == 'a':
                mask = mask ^ (1 << 0)
            elif s[i] == 'e':
                mask = mask ^ (1 << 1)
            elif s[i] == 'i':
                mask = mask ^ (1 << 2)
            elif s[i] == 'o':
                mask = mask ^ (1 << 3)
            elif s[i] == 'u':
                mask = mask ^ (1 << 4)

            
            if mask in mp:
                ans = max(ans, i - mp[mask])
            else:
                mp[mask] = i

        return ans






# class Solution:
#     def findTheLongestSubstring(self, s: str) -> int:
#         mp = {"00000": -1}
#         state = [0] * 5
#         currState = "00000"
#         ans = 0

#         for i in range(len(s)):
#             if s[i] == 'a':
#                 state[0] = (state[0] + 1) % 2
#             elif s[i] == 'e':
#                 state[1] = (state[1] + 1) % 2
#             elif s[i] == 'i':
#                 state[2] = (state[2] + 1) % 2
#             elif s[i] == 'o':
#                 state[3] = (state[3] + 1) % 2
#             elif s[i] == 'u':
#                 state[4] = (state[4] + 1) % 2

#             currState = ''.join(str(x) for x in state)

#             if currState in mp:
#                 ans = max(ans, i - mp[currState])
#             else:
#                 mp[currState] = i

#         return ans