#include<iostream>
//#include<string>

using namespace std;
class Solution {
public:
    string removeOuterParentheses(string S) {
        int opened = 0;
        int closed = 0;
        int moduleStart = 0;
        string ret = "";
        for (unsigned int i=0;i<S.size();i++){
        	if (S[i] == '('){
        		opened++;
        	}
            else{
                closed++;
            }
        	if (opened == closed){
        		ret += S.substr(moduleStart+1, i-moduleStart-1);
                moduleStart = i+1;
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