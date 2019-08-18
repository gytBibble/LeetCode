class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2)
            return s;
        vector<string> sArrays(numRows, "");
        int inc = 1;
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(inc) {
                sArrays[count] += s[i];
                count++;
                if(count == numRows) {
                    inc = 0;
                    count = numRows - 2;
                }
            }
            else {
                sArrays[count] += s[i];
                count--;
                if(count == -1) {
                    inc = 1;
                    count = 1;
                }
            }
        }
        string res;
        for(int i = 0; i < numRows; ++i)
            res += sArrays[i];
        return res;
    }
};