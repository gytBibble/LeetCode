class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int len = s.size();
        for(int i = 0; i < len; ++i) {
            if(s[i] == 'I') {
                if(i + 1 < len) {
                    if(s[i + 1] == 'V') {
                        res += 4;
                        i++;
                        continue;
                    }
                    else if(s[i + 1] == 'X'){
                        res += 9;
                        i++;
                        continue;
                    }
                }
                res += 1;
            }
            else if(s[i] == 'X') {
                if(i + 1 < len) {
                    if(s[i + 1] == 'L') {
                        res += 40;
                        i++;
                        continue;
                    }
                    else if(s[i + 1] == 'C'){
                        res += 90;
                        i++;
                        continue;
                    }
                }
                res += 10;
            }
            else if(s[i] == 'C') {
                if(i + 1 < len) {
                    if(s[i + 1] == 'D') {
                        res += 400;
                        i++;
                        continue;
                    }
                    else if(s[i + 1] == 'M'){
                        res += 900;
                        i++;
                        continue;
                    }
                }
                res += 100;
            }
            else if(s[i] == 'M') {
                res += 1000;
            }
            else if(s[i] == 'D') {
                res += 500;
            }
            else if(s[i] == 'L') {
                res += 50;
            }
            else if(s[i] == 'V') {
                res += 5;
            }
        }
        return res;
    }
};