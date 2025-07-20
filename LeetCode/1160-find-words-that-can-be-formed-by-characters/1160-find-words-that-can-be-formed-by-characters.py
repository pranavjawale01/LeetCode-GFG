class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        def findCharCount(s):
            return Counter(s)

        charCount = findCharCount(chars)
        total_count = 0

        for word in words:
            wordCount = findCharCount(word)
            check = all(wordCount[ch] <= charCount[ch] for ch in word)

            if check:
                total_count += len(word)

        return total_count