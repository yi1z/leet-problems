class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2){
            return 0;
        }

        // initialize a stack and a dp array
        vector<int> ts;
        vector<int> dp (s.size(), 0);

        for (int i = 0; i < s.size(); i ++){
            // if left parenthese, add its index to stack
            if (s[i] == '('){
                ts.push_back(i);
            }

            // if right parenthese
            else{
                // check if stack is not empty
                if (! ts.empty()){
                    // if so, pop the last item
                    // this is the index of the corresponding left parenthese
                    int left = ts.back();
                    ts.pop_back();
                    // current length is i - left + 1
                    // previous length is dp[left - 1], the length of the last parenthesis
                    dp[i] = i - left + 1 + dp[left > 0 ? left - 1 : 0];
                }
            }
        }

        int max_length = 0;
        for (int i = 0; i < dp.size(); i++) {
            max_length = max(max_length, dp[i]);
        }

        return max_length;

    }
};