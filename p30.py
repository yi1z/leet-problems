class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        word_len = len(words[0])

        front = len(words) * word_len
        back = 0
        result = []
        words = sorted(words)

        while front <= len(s):
            # make a copy
            temp = words.copy()
            # partition the strings
            partition = []
            for i in range(back, front, word_len):
                partition.append(s[i : i + word_len])

            # check if the current partition is the same as the words
            partition = sorted(partition)
            if temp == partition:
                result.append(back)

            back += 1
            front += 1

        return result
        