class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        def split_words(sentence: str):
            return sentence.split()

        words1 = split_words(sentence1)
        words2 = split_words(sentence2)

        if len(words1) < len(words2):
            words1, words2 = words2, words1

        start = 0
        end = 0
        n1, n2 = len(words1), len(words2)

        while start < n2 and words1[start] == words2[start]:
            start += 1

        while end < n2 and words1[n1 - end - 1] == words2[n2 - end - 1]:
            end += 1

        return start + end >= n2