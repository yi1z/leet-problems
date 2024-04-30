class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        if (nums.size() == 3){
            return nums[0] + nums[1] + nums[2];
        }

        // sort the nums
        sort(nums.begin(), nums.end());

        int front, back, sum;
        sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); i ++){
            // get the current front and back
            front = i + 1;
            back = nums.size() - 1;

            while (front < back){

                // get the curr sum
                int curr_sum = nums[front] + nums[back] + nums[i];

                // if this sum is closer than the previous sum
                if (abs(curr_sum - target) <= abs(sum - target)){
                    sum = curr_sum;
                }

                // if curr_sum is larger, move back closer to front
                if (curr_sum > target){
                    back --;
                }

                // if curr_sum is smaller, move front closer to back
                else if (curr_sum < target){
                    front ++;
                }

                // if is target, return
                else{
                    return curr_sum;
                }

            }
        }

        return sum;
    }
};