class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.size() < needle.size()) return -1;
        int index = -1;
        bool found;
        int cur = 0, max = haystack.size() - needle.size();
        while(cur <= max){
            found = true;
            for(int i = 0; i < needle.size(); ++i){
                if(haystack[cur + i] != needle[i]){
                    found = false;
                    break;
                }
            }
            if(found){
                index = cur;
                break;
            }
            cur++;
        }
        return index;
    }
};