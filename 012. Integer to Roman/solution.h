class Solution {
public:
    string intToRoman(int num) {
        string I[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; // 0 ~ 9
        string X[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; // 10 ~ 90
        string C[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; // 100 ~ 900
        string M[4] = {"", "M", "MM", "MMM"};                                        // 1000 ~ 3000
        return M[num / 1000] + C[num / 100 % 10] + X[num / 10 % 10] + I[num % 10];
    }
};