class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        dict = set(wordList)
        
        if endWord not in dict:
            return 0
        
        q = deque([beginWord])
        count = 1
        
        while q:
            n = len(q)
            for _ in range(n):
                temp = q.popleft()
                if temp == endWord:
                    return count
                dict.discard(temp)
                
                for j in range(len(temp)):
                    original_char = temp[j]
                    for k in range(26):
                        char = chr(ord('a') + k)
                        newWord = temp[:j] + char + temp[j + 1:]
                        if newWord in dict:
                            q.append(newWord)
                            dict.discard(newWord)
                    temp = temp[:j] + original_char + temp[j + 1:]
            count += 1
        
        return 0