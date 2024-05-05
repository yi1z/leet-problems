class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int n = nums.size();

        // for each index in nums
        for (int i = 0; i < n; ++i){

            // if nums[i] is in range(0, n + 1)
            // if nums[i] does not equal to i + 1, i.e., is not the corresponding positive number
            // if nums[i] and nums[nums[i] - 1] are not duplicates
            while (0 < nums[i] && nums[i] < n + 1 && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]){
                // keet swapping nums[i] and nums[nums[i] - 1]
                // until they collide
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        // find the first number that show a gap
        for (int i = 0; i < n; ++i){
            if (nums[i] == i + 1){
                continue;
            }
            return i + 1;
        }

        return n + 1;
    }
};