class Solution:
    def binarySearch(self, nums, target, is_left):
        left = 0
        right = len(nums) - 1
        result = -1

        # while we have not gone through the whole list
        # note: we need to use <= here as to make sure we get all the numbers
        while left <= right:
            mid = (left + right) // 2
            # if less than target
            if nums[mid] < target:
                # mvoe to the right half
                left = mid + 1
            # if larger than target
            elif nums[mid] > target:
                # move to the left half
                right = mid - 1
            # if is target
            else:
                # store this first
                result = mid
                # if we want the left most target
                if is_left:
                    # move to the left half
                    right = mid - 1
                # if right most target
                else:
                    left = mid + 1
        
        return result

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return [self.binarySearch(nums, target, True), self.binarySearch(nums, target, False)]