#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp = 't';
        for (unsigned int i=0;i<s.size()/2;i++){
        	temp = s[i];
        	s[i] = s[s.size()-i-1];
        	s[s.size()-i-1] = temp;
        }
    }

    void printVec(vector<char> p){
    	for (unsigned int i=0;i<p.size();i++){
    		cout<<p[i]<<',';
    	}
    	cout<<endl;
    }
};

int main(){
	Solution sol;
	vector<char> get = {'h','e','l','l','o','w'};
	sol.printVec(get);
	sol.reverseString(get);
	sol.printVec(get);
	return 0;
}