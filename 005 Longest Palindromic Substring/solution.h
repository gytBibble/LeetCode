class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 1) return "";
        int start = 0, len = 0;
        for(int i = 0; i < s.size(); ++i) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            if(len1 > len2 && len1 > len) {
                len = len1;
                start = i - (len - 1) / 2;
            }
            else if(len2 > len) {
                len = len2;
                start = i - (len - 2) / 2;
            }
        }
        return s.substr(start, len);
    }
    
    int expandAroundCenter(string s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // the length of substring
    }
};