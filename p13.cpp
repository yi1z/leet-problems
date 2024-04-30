class Solution {
public:
    int convert(char c){
        if (c == 'I'){
            return 1;
        }
        else if (c == 'V'){
            return 5;
        }
        else if (c == 'X'){
            return 10;
        }
        else if (c == 'L'){
            return 50;
        }
        else if (c == 'C'){
            return 100;
        }
        else if (c == 'D'){
            return 500;
        }
        else if (c == 'M'){
            return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        int n = s.length();
        
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return convert(s[0]);
        }

        int result = 0;
        int i = 0;
        while (i < n){
            int curr = convert(s[i]);
            // check if the next character is larger
            int next = convert(s[i + 1]);
            if (curr < next){
                result += next - curr;
                i += 1;
            }
            else{
                result += curr;
            }
            i += 1;
        }
        return result;
    }
};