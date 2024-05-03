class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2){
            return nums.size();
        }

        int k = 1;
        for (int i = 1; i < nums.size(); i ++){
            if (nums[i] != nums[i - 1]){
                nums[k] = nums[i];
                k += 1;
            }
        }

        return k;
    }
};