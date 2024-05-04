class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if len(s) < 2:
            return 0

        # initialize a stack and a dp array
        stack = []
        dp = [0] * len(s)

        for i in range(len(s)):
            # if left parenthese, add its index to stack
            if s[i] == "(":
                stack.append(i)

            # if right parenthese
            else:
                # check if stack is not empty
                if stack:
                    # if so, pop the last item
                    # this is the index of the corresponding left parenthese
                    left = stack.pop()
                    # current length is i - left + 1
                    # previous length is dp[left - 1], the length of the last parenthesis
                    dp[i] = i - left + 1 + dp[left - 1]

        return max(dp)
