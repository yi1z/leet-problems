class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        dp = []
        for num in candidates:
            dp.append([num])

        result = []
        seen = []

        while dp:
            curr = dp.pop(0)
            curr_sum = sum(curr)
            if curr_sum == target:
                # check for duplicates
                temp = sorted(curr)
                if temp not in seen:
                    result.append(curr)
                    seen.append(temp)
            elif curr_sum < target:
                for num in candidates[candidates.index(curr[-1]) : ]:
                    dp.append(curr + [num])

        return result
        