class Solution:
    def comb(self, idx, target, nums, result, dstack):
        # if we get the target
        if target == 0:
            result.append(dstack.copy())
            return
        
        # for all the numbers we have not considered
        for i in range(idx, len(nums)):
            # if the number exceeds
            if nums[i] > target:
                break
            
            # if the number is not the first, and it equals its previous
            # then we can safely omit this number, since recursive will take 
            # care of all numbers
            if i > idx and nums[i] == nums[i - 1]:
                continue

            # push current number to the stack
            dstack.append(nums[i])
            # recursive call
            self.comb(i + 1, target - nums[i], nums, result, dstack)
            # pop last numer
            dstack.pop()

        
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
        nums = sorted(nums)
        result = []
        dstack = []
        self.comb(0, target, nums, result, dstack)
        return result