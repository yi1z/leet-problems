class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(haystack) < len(needle):
            return -1

        front = len(needle)

        while front <= len(haystack):
            if haystack[front - len(needle) : front] == needle:
                return front - len(needle)
            
            front += 1

        return -1
