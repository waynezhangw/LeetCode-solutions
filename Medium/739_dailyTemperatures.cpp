#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<stack>

using std::vector;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {   //it works, but just Time Limit Exceeded, O(n)^2 is bad
    	vector<int>::size_type j;
    	for (vector<int>::size_type i=0;i<T.size();i++) {
    		for (j=i+1;j<T.size();j++) {
    			if (T[i]<T[j]) break;
    		}
    		T[i] = j == T.size() ? 0 : j-i;
    	}
        return T;
    }
    //因为温度范围小，但天数长，所以可用空间换时间?
    vector<int> dailyTemperatures2(vector<int>& T) {  //from discussion idea, 95.86% and 81.89%
    	int length = (int)T.size();
    	vector<int> ret(T.size());
    	for (int i=length-1;i>=0;i--) {
    		for (int j=i+1;j<length;j+=ret[j]) {  //key idea is j+=ret[j]
    			if (T[i]<T[j]) {
    				ret[i] = j-i;
    				break;
    			}
    			if (ret[j] == 0) {
    				ret[i] = 0;
    				break;
    			}
    		}
    	}
        return ret;
    }
    vector<int> dailyTemperatures3(vector<int>& T) {  //from discussion code, 92.85% and 78.33
    	int length = (int)T.size();
    	vector<int> ret(T.size());
    	for (int i=length-1;i>=0;i--) {
    		int j = i+1;
    		while (j < length && T[i] >= T[j]) {
    			if (ret[j] == 0) j = length;
    			else j += ret[j];             //key idea is j+=ret[j]
    		}
    		ret[i] = j == length ? 0 : j-i;
    	}
        return ret;
    }
    vector<int> dailyTemperatures4(vector<int>& T) {  //from discussion code, stack method, 69.29% and 22.57%
    	std::stack<int> myStack;
    	vector<int> ret(T.size());
    	for (int i=0;i<(int)T.size();i++) {
    		// if the current temperate is greater than the top of stack, 
    		// it means we find a warmer temperature, pop the element from the stack and update result
    		while (!myStack.empty() && T[i]>T[myStack.top()]) {
    			int idx = myStack.top();
    			myStack.pop();
    			ret[idx] = i - idx;
    		}
    		myStack.push(i);      //if current T is not large enough, we will continue to search the larger one
    	}
    	return ret;
    }
};

int main () {
	Solution sol;
	vector<int> vec = {73, 74, 75, 71, 69, 72, 76, 73};
	vec = sol.dailyTemperatures4(vec);
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}