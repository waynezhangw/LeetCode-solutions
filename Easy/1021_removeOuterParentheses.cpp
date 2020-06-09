#include<iostream>
//#include<string>

using namespace std;
class Solution {
public:
    string removeOuterParentheses(string S) {
        int opened = 0;
        string ret;
        for (char c : S){
        	if (c == '(' && opened++ > 0){
        		ret += c;
        	}
        	if (c == ')' && opened-- > 1){
        		ret += c;
        	}
        }
        return ret;
    }
};

int main(){
	Solution sol;
	cout<<sol.removeOuterParentheses("(()())(())(()(()))")<<endl;
	return 0;
}