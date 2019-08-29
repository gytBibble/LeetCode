class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backTrack(res, "", 0, 0, n);
        return res;
    }
    void backTrack(vector<string> &res, string cur, int left, int right, int max) {
        if(cur.size() == 2 * max) {
            res.push_back(cur);
            return;
        }
        if(left < max) backTrack(res, cur + "(", left + 1, right, max);
        if(right < left) backTrack(res, cur + ")", left, right + 1, max);
    }
};