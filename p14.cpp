class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1){
            return strs[0];
        }

        string result = "";
        // sort the strings
        sort(strs.begin(), strs.end());
        for (int i = 0; i < strs[0].size(); i ++){
            if (i >= strs[strs.size() - 1].size()){
                return result;
            }

            if (strs[0][i] != strs[strs.size() - 1][i]){
                return result;
            }

            result += strs[0][i];
        }
        return result;
    }
};