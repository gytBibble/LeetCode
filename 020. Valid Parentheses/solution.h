class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            if(stk.empty()) return false;
            else if(s[i] == ')') {
                if(stk.top() != '(') return false;
                stk.pop();
            }
            else if(s[i] == ']') {
                if(stk.top() != '[') return false;
                stk.pop();
            }
            else if(s[i] == '}') {
                if(stk.top() != '{') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};