#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        recursionParenthesis("", result, n, n);
        return result;
    }

    void recursionParenthesis(string str, vector<string> &result, int left, int right){
    	if (left == 0 && right == 0) {
    		result.push_back(str);
    		return;
    	}
    	else {
    		if (left > 0) {
    			recursionParenthesis(str+"(", result, left-1, right);  //因为最左边的永远首先是左括号
    		}
    		if (left < right) {
    			recursionParenthesis(str+")", result, left, right-1);
    		}
    	}
    }

    void seeVector(vector<string> &result) {
    	for (unsigned int i=0;i<result.size();i++) {
    		cout<<result[i]<<endl;
    	}
    }
};

int main() {
	Solution sol;
	vector<string> result = sol.generateParenthesis(3);
	sol.seeVector(result);
	return 0;
}