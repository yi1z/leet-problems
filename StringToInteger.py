class Solution:
    def myAtoi(self, s: str) -> int:
        # ignore all leading white spaces
        i = 0
        while i < len(s):
            if s[i] == " ":
                i += 1
            else:
                break
        
        # check if s is completely blank
        if i == len(s):
            return 0

        result = ""
        # check for - or + sign
        if s[i] in ['-', '+']:
            result += s[i]
            i += 1
        # reads the later numbers
        nums = []
        for j in range(10):
            nums.append(str(j))

        ceil = 2 ** 31 - 1
        floor = - 2 ** 31
        
        while i < len(s):
            if s[i] in nums:
                result += s[i]
                i += 1
            # if a non digit character appears
            else:
                # ignore the rest of the string
                break
        
        # if no digits are read, return 0
        if result in ["", "+", '-']:
            return 0

        result = int(result)
        if result > ceil:
            return ceil
        if result < floor:
            return floor

        return int(result)
