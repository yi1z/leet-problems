class Solution {
public:
    bool isValid(string s) {
        int small = 0;
        int medium = 0;
        int large = 0;

        vector<char> cancle;
        for (char c: s){

            if (c == '('){
                small ++;
                cancle.push_back(c);
            }
            if (c == ')'){
                small --;
                if (cancle.empty() || cancle.back() != '('){
                    return false;
                }
                cancle.pop_back();
            }

            if (c == '['){
                medium ++;
                cancle.push_back(c);
            }
            if (c == ']'){
                medium --;
                if (cancle.empty() || cancle.back() != '['){
                    return false;
                }
                cancle.pop_back();
            }

            if (c == '{'){
                large ++;
                cancle.push_back(c);
            }
            if (c == '}'){
                large --;
                if (cancle.empty() || cancle.back() != '{'){
                    return false;
                }
                cancle.pop_back();
            }

            if (small < 0 || medium < 0 || large < 0){
                return false;
            }
        }

        if (small > 0 || medium > 0 || large > 0){
            return false;
        }
        return true;
    }
};