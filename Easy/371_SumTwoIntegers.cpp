#include<iostream>

class Solution {
public: 
    int getSum(int a, int b) {   //think from Knives-out-offer
        while (b != 0) {
        	int sum = a ^ b;
        	int jin = (unsigned int)(a&b)<<1;   //negative int shift left is not defined in C++
        	a = sum;
        	b = jin;
        }
        return a;
    }
};

int main() {
	Solution sol;
	std::cout<<sol.getSum(-2,1)<<std::endl;
	return 0;
}