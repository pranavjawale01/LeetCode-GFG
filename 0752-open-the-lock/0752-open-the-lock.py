from collections import deque

class Solution:
    def fill_neighbors(self, que, curr, dead):
        for i in range(4):
            ch = curr[i]

            dec = '9' if ch == '0' else chr(ord(ch) - 1)
            inc = '0' if ch == '9' else chr(ord(ch) + 1)

            curr[i] = dec
            if ''.join(curr) not in dead:
                dead.add(''.join(curr))
                que.append(list(curr))

            curr[i] = inc
            if ''.join(curr) not in dead:
                dead.add(''.join(curr))
                que.append(list(curr))
            curr[i] = ch

    def openLock(self, deadends: List[str], target: str) -> int:
        dead = set(deadends)

        start = ['0', '0', '0', '0']
        if ''.join(start) in dead:
            return -1

        que = deque()
        que.append(start)

        level = 0
        while que:
            n = len(que)

            for _ in range(n):
                curr = que.popleft()
                if curr == list(target):
                    return level

                self.fill_neighbors(que, curr, dead)
            level += 1
        return -1