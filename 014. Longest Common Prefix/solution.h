class Solution_1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        int i;
        for(i = 0; i < strs[0].size(); ++i) {
            for(int j = 1; j < strs.size(); ++j) {
                if(i >= strs[j].size() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};