class Solution_1 { // Time Limit Exceeded
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || dividend == 0) return 0;
        int sign = 1;
        if(dividend > 0) {
            sign = -sign;
            dividend = -dividend;
        }
        if(divisor > 0) {
            sign = -sign;
            divisor = -divisor;
        }
        if(dividend == divisor) return sign;
        int res = 0;
        while(dividend <= divisor){
            res--;
            dividend -= divisor;
        }
        if(sign == 1){
            if(res == 0x80000000) return 0x7fffffff;
            res = -res;
        }
        return res;
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return 0;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long dd = labs(dividend), dr = labs(divisor), res = 0;
        while(dd >= dr){
            long temp = dr, count = 1;
            while(temp << 1 < dd){
                temp <<= 1;
                count <<= 1;
            }
            res += count;
            dd -= temp;
        }
        if(sign == -1) res = -res;
        return (int)res;
    }
};