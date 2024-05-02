class Solution:
    def insert(self, to: str):
        result = []
        for i in range(0, len(to) - 1):
            if to[i] == "(" and to[i + 1] == ")":
                result.append(to[:i + 1] + "()" + to[i + 1:])
                result.append(to[:i + 1] + "(" + to[i+1 : i+3] + ")" + to[i+3: ])

        result.append(to + "()")
        result.append("(" + to + ")")
        
        return result

    def generateParenthesis(self, n: int) -> List[str]:
        if n == 1:
            return ["()"]
        
        prev = self.generateParenthesis(n - 1)
        result = []

        for comb in prev:
            result.extend(self.insert(comb))

        result = list(set(result))
        return result
