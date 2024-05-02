class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int target, int first_i, int second_i){

        vector<vector<int>> result;

        for (int a = second_i + 1; a < nums.size(); a ++){
            if (a > second_i + 1 && nums[a - 1] == nums[a]){
                continue;
            }
            for (int b = a + 1; b < nums.size(); b ++){
                if (b > a + 1 && nums[b - 1] == nums[b]){
                    continue;
                }
                long temp = target;
                temp = temp - nums[first_i] - nums[second_i] - (nums[a] + nums[b]);
                if (temp == 0){
                    vector<int> temp {nums[first_i], nums[second_i], nums[a], nums[b]};
                    result.emplace_back(temp);
                    break;
                }
            }
        }
        return result;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4){
            // int temp = 0;
            // vector<int> quadra;
            // for (int num: nums){
            //     temp += num;
            //     quadra.push_back(num);
            // }
            // if (temp == target){
            //     result.push_back(quadra);
            // }
            return result;
        }

        sort(nums.begin(), nums.end());
        int c, d;

        for (int a = 0; a < nums.size(); a ++){
            // omit repeated numbers
            if (a > 0 and nums[a] == nums[a - 1]){
                continue;
            }
            for (int b = a + 1; b < nums.size(); b ++){
                // omit repeated numbers
                if (b > a + 1 and nums[b] == nums[b - 1]){
                    continue;
                }

                c = b + 1;
                d = nums.size() - 1;

                while (c < d){
                    long sum = nums[a];
                    sum += nums[b];
                    sum += nums[c];
                    sum += nums[d];
                    if (sum < target){
                        c ++;
                    }
                    else if (sum > target){
                        d --;
                    }
                    else{
                        vector<int> t = {nums[a], nums[b], nums[c], nums[d]};

                        if (find(result.begin(), result.end(), t) == result.end()){
                            result.push_back(t);
                        }
                        c ++;
                        d --;

                        // omit the repeated numbers
                        while (c < d and nums[c] == nums[c - 1]){
                            c ++;
                        }
                        while (c < d and nums[d] == nums[d + 1]){
                            d --;
                        }
                    }
                }

            }
        }

        return result;
    }
};