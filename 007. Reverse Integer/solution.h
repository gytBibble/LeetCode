class Solution_1 { // so complex
public:
    int reverse(int x) {
        if(x == 0) return x;
        int s = 1;
        if(x < 0)
            s = -1;
        long temp = long(x) * s; // !!!
        vector<int> integer;
        int index = 0;
        int flag = 1;
        while(temp > 0) {
            int mod = temp % 10;
            if(flag && mod == 0) { // remove the leading 0
                temp /= 10;
                continue;
            }
            flag = 0;
            integer.push_back(mod);
            index++;
            if(index > 10)
                return 0;
            temp /= 10;    
        }
        long now = 1;
        for(int i = index - 1; i >= 0; --i) {
            temp += now * integer[i];
            now *= 10;
        }
        temp *= s;
        // overflow
        int a = 0x80000000, b = 0x7fffffff;
        if(temp < a || temp > b)
            return 0;
        return (int) temp;
    }
};

class Solution_2 { // simplify the Solution_1
public:
    int reverse(int x) {
        long res = 0;
        while(x) {
            res = res * 10 + x % 10;
            x /= 10;
            if(res > INT_MAX || res < INT_MIN)
                return 0;
        }
        return (int) res;
    }
};

class Solution_3 { // not use the long int
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        if(x < 0)
            return -reverse(-x);
        int res = 0;
        while(x) {
            int mod = x % 10;
            x /= 10;
            // check res would overflow
            if((INT_MAX - mod) / 10 < res)
                return 0;
            res = res * 10 + mod;
        }
        return res;
    }
};