class Solution {
public:
    vector<string> numToLetter(char num){
        vector<string> t;
        if (num == '2'){
            vector<string> t {"a", "b", "c"};
            return t;
        }
        if (num == '3'){
            vector<string> t {"d", "e", "f"};
            return t;
        }
        if (num == '4'){
            vector<string> t {"g", "h", "i"};
            return t;
        }
        if (num == '5'){
            vector<string> t {"j", "k", "l"};
            return t;
        }
        if (num == '6'){
            vector<string> t {"m", "n", "o"};
            return t;
        }
        if (num == '7'){
            vector<string> t {"p", "q", "r", "s"};
            return t;
        }
        if (num == '8'){
            vector<string> t {"t", "u", "v"};
            return t;
        }
        if (num == '9'){
            vector<string> t {"w", "x", "y", "z"};
            return t;
        }
        return t;
    }

    vector<string> mergeComb(vector<string> combs, vector<string> to_merge){
        vector<string> result;
        for (string comb_str: combs){
            for (string to_str: to_merge){
                result.push_back(comb_str + to_str);
            }
        }
        return result;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0){
            vector<string> t {};
            return t;
        }

        vector<string> result = numToLetter(digits[0]);
        for (int i = 1; i < digits.size(); i ++){
            result = mergeComb(result, numToLetter(digits[i]));
        }
        return result;
    }
};