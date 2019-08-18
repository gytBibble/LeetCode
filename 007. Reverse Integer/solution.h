class Solution {
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