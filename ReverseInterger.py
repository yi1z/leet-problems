class Solution:
    def reverse(self, x: int) -> int:
        ceil = (2 ** 30 - 1) + 2 ** 30
        ceil = str(ceil)

        floor = -(2 ** 31)
        floor = str(floor)

        x_str = str(x)
        is_n = False
        if x < 0:
            x_str = x_str[1:]
            is_n = True

        need_check = True
        if len(x_str) < len(ceil):
            need_check = False

        result = ""
        for i in range(0, len(x_str)):
            result += x_str[-i - 1]
            # check if the interger is in range
            if need_check:
                if is_n:
                    if result[i] > floor[i + 1]:
                        return 0
                    elif result[i] < floor[i + 1]:
                        need_check = False
                else:
                    if result[i] > ceil[i]:
                        return 0
                    elif result[i] < ceil[i]:
                        need_check = False
        
        if is_n:
            result = "-" + result
        
        return int(result)
