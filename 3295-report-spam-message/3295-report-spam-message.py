class Solution:
    def reportSpam(self, message: List[str], bannedWords: List[str]) -> bool:
        st = set(bannedWords)
        count = 0
        for s in message:
            if s in st:
                count += 1
        return count >= 2