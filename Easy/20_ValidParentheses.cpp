#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>

using std::stack;
using std::unordered_map;
using std::string;
class Solution {
public:
    bool isValid(string s) {            //my stack method, 30.89% 17.56%
        unordered_map<char, char> mp;
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        stack<char> stk;
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
            else {
                if (!stk.empty() && stk.top() == mp[s[i]]) {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
        }
        return stk.empty() ? true : false;
    }

    bool isValid2(string s) {            //from discussion, a clear method, 100.00% 35.22%
        stack<char> stk;
        for (auto c : s) {
            if (c == '(') stk.push(')');
            else if (c == '[') stk.push(']');
            else if (c == '{') stk.push('}');
            else if (stk.empty() || stk.top() != c) return false;
            else stk.pop();
        }
        return stk.empty();
    }
};

int main() {
    Solution sol;
    // string str = "()[]{}";
    string str = "([()])";
    std::cout << sol.isValid2(str) << std::endl;
    return 0;
}