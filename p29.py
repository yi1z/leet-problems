class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if (dividend == -2147483648) and divisor == -1:
            return 2147483647
        
        is_negative = False
        if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
            is_negative = True

        dividend, divisor = abs(dividend), abs(divisor)
        result = 0

        for i in range(32)[::-1]:
            # if dividend is larger than divisor after current shift
            if (dividend >> i) - divisor >= 0:
                # the amount of divisor in dividend is equal to the current digit
                result += 1 << i
                # remove this part of dividend
                dividend -= divisor << i

        return -result if is_negative else result
