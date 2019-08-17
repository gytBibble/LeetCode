class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0, start = -1;
        vector<int> exist(256, -1);
        for(int i = 0; i < s.size(); ++i) {
            if(exist[s[i]] > start)
                start = exist[s[i]];
            exist[s[i]] = i;
            len = max(len, i - start);
        }
        return len;
    }
};