class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'

        if n == 2:
            return '11'
        
        prev = self.countAndSay(n - 1)

        back = 0
        front = 1
        result = ""

        while front <= len(prev):
            # move to the last repeat number
            while front < len(prev) and prev[front] == prev[back]:
                front += 1
            
            # current length front - back
            result += str(front - back) + str(prev[back])

            # move to the next section
            back = front
            front = front + 1
        return result
