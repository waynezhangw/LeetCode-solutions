#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <iterator>     // std::back_inserter
#include <stdlib.h>     /* atoi */

using std::string;
using std::vector;
using std::cout;
class Solution {
public:
    bool isHappy(int n) {         //only faster than 5.75% and 7.69%
    	int times = 0;
        while (n != 1) {
        	int sum = 0;
        	string numStr = std::to_string(n);
        	vector<int> vec;
        	std::copy(numStr.begin(), numStr.end(), std::back_inserter(vec));
        	for (vector<int>::size_type i=0;i<vec.size();i++) {
        		int digit = vec[i]-48;
        		sum += digit*digit;
        	}
        	n = sum;
        	times++;
        	// cout<<n<<std::endl;
        	if (times>100) return false;
        }
        return true;
    }
    bool isHappy2(int n) {         //used others' digitSquareSum idea
    	int times = 0;
        while (n != 1) {
        	int sum = 0;
        	while (n != 0) {
        		int digit = n % 10;
        		sum += digit*digit;
        		n /= 10;
        	}
        	n = sum;
        	times++;
        	// cout<<n<<std::endl;
        	if (times>100) return false;
        }
        return true;
    }
};

int main () {
	Solution sol;
	std::cout<<sol.isHappy2(19)<<std::endl;
	return 0;
}