class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        n = len(s)
        if n % 2 != 0:
            return False

        open_count, free_count = 0, 0
        for i in range(n):
            if locked[i] == '0':
                free_count += 1
            elif s[i] == '(':
                open_count += 1
            else:
                if open_count > 0:
                    open_count -= 1
                elif free_count > 0:
                    free_count -= 1
                else:
                    return False

        close_count, free_count = 0, 0
        for i in range(n - 1, -1, -1):
            if locked[i] == '0':
                free_count += 1
            elif s[i] == ')':
                close_count += 1
            else:
                if close_count > 0:
                    close_count -= 1
                elif free_count > 0:
                    free_count -= 1
                else:
                    return False

        return True