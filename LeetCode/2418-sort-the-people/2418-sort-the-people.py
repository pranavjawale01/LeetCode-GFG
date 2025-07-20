class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        n = len(names)
        vec = [(names[i], heights[i]) for i in range(n)]
        vec.sort(key=lambda x: x[1], reverse=True)
        sorted_names = [name for name, _ in vec]
        return sorted_names