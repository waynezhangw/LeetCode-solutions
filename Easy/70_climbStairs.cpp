#include<iostream>

class Solution {
public:
    int climbStairs(int n) {
    	int a1 = 1, a2 = 2; 
    	if (n<1) return 0;
        else if (n==1) return a1;
        else if (n==2) return a2;
        else {
        	int method = 0;
        	for (int i=2;i<n;i++) {
        		method = a1+a2;
        		a1 = a2;
        		a2 = method;
        	}
        	return method;
        }
    }
};

int main () {
	Solution sol;
	std::cout<<sol.climbStairs(4)<<std::endl;
	return 0;
}