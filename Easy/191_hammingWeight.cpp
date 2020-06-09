#include<iostream>
#include <bitset>         // std::bitset

typedef unsigned int uint32_t;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while (n != 0) {
        	if ( (n&1) == 1) {
        		num++;
        	}
        	n = n>>1;
        }
        return num;
    }
    int hammingWeight2(uint32_t n) {
        return __builtin_popcount(n);
    }
    int hammingWeight3(uint32_t n) {
        return std::bitset<32>(n).count();
    }
};

int main () {
	Solution sol;
	std::cout<<sol.hammingWeight3(8)<<std::endl;
	return 0;
}