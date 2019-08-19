class Solution {
public:
    int myAtoi(string str) {
        int sign = 0;
        int res = 0;
        bool isLead = true;
        for(int i = 0; i < str.size(); ++i) {
            // ignore the leading space char
            if(isLead && str[i] == ' ')
                continue;
            isLead = false;
            if(sign == 0 && str[i] == '-') {
                sign = -1;
                continue;
            }
            if(sign == 0 && str[i] == '+') {
                sign = 1;
                continue;
            }
            if(str[i] >= '0' && str[i] <= '9') {
                if(sign == 0)
                    sign = 1;
                // check is overflow
                int cur = str[i] - '0';
                if( sign == -1) {
                    if((INT_MIN + cur) / 10 > -res || (res == 214748364 && cur == 8))
                        return INT_MIN;
                }
                else {
                    if((INT_MAX - cur) / 10 < res)
                        return INT_MAX;
                }
                res = 10 * res + cur;
            }
            else
                break;
        }
        return sign * res;
    }
};