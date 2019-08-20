class Solution_1 { // Recursive
public:
    bool isMatch(string s, string p) {
        if(p.empty()) {
            return s.empty();
        }
        bool first_match = !s.empty() && (p[0] == '.' || p[0] == s[0]);
        if(p.size() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        }
        else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

class Solution_2 {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        // dp[i][0] = false when i > 0; so j start from 1
        for(int i = 0; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(p[j - 1] == '*') {
                    // p[0] cannot be '*' so no need check "j >= 2" here
                    dp[i][j] = dp[i][j - 2]
                        || (i >= 1 && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = (i >= 1) && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};