class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>{};
        vector<string> res;
        const string En[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for(int i = 0; i < digits.size(); ++i) {
            vector<string> tmpRes;
            string now = En[digits[i] - '2'];
            for(int j = 0; j < res.size(); ++j) {
                for(int k = 0; k < now.size(); ++k) {
                    tmpRes.push_back(res[j] + now[k]);
                }
            }
            res = tmpRes;
        }
        return res;
    }
};