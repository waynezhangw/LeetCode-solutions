#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;
using std::endl;

class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) { //4 ms, faster than 72.70%, 9.1 MB, less than 76.75%
        string ret = "";
        int prefixNum = 0;
        while (true) {
            if (prefixNum > int(strs[0].size())-1) break;
            char tmp = strs[0][prefixNum];
            bool hasDiff = false;
            for (unsigned int i = 1; i < strs.size(); i++) { // kind of vertical scanning
                if (prefixNum > int(strs[i].size())-1 || strs[i][prefixNum] != tmp) {
                    hasDiff = true;
                    break;
                }
            }
            if (hasDiff) {
                break;
            } else {
                ret += tmp;
                prefixNum++;
            }
        }
        return ret;
    }

    // after seeing the official vertical scanning method
    string longestCommonPrefix2(vector<string>& strs) { //4 ms, faster than 72.33%, 9.2 MB, less than 78.18% 
        if (strs.size() == 0) return "";
        for (unsigned int i = 0; i < strs[0].size(); i++) { // kind of vertical scanning
            char tmp = strs[0][i];
            for (unsigned int j = 1; j < strs.size(); j++) {
                if (i == strs[j].size() || strs[j][i] != tmp) {
                    return strs[j].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    Solution sol;
    vector<string> vec1 = {"flower","flow","flight"};
    vector<string> vec2 = {"dog","racecar","car"};
    cout << sol.longestCommonPrefix(vec1) << " over" << endl;
    cout << sol.longestCommonPrefix(vec2) << " over" << endl;
    cout << sol.longestCommonPrefix2(vec1) << " over" << endl;
    cout << sol.longestCommonPrefix2(vec2) << " over" << endl;
    return 0;
}