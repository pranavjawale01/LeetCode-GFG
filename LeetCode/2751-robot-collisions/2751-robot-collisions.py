class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        idx = list(range(n))

        idx.sort(key=lambda x: positions[x])

        st = []
        for id in idx:
            if directions[id] == 'R':
                st.append(id)
            else:
                while st and healths[id] > 0:
                    if healths[id] > healths[st[-1]]:
                        healths[id] -= 1
                        healths[st.pop()] = 0
                    elif healths[id] < healths[st[-1]]:
                        healths[id] = 0
                        healths[st[-1]] -= 1
                    else:
                        healths[id] = 0
                        healths[st.pop()] = 0

        return [health for health in healths if health > 0]