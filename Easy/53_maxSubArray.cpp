#include<iostream>
#include<vector>
#include <numeric>      // std::accumulate
#include <algorithm>    // std::max

using std::vector;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {      // only faster than 5.10%, 24.45%
        vector<int>::const_iterator left = nums.begin(), right = nums.begin()+1;
        int ret = nums[0];
        while (left<=nums.end() && right<=nums.end()) {
        	int temp = accumulate(left, right, 0);
        	ret = temp > ret ? temp:ret;
        	if (temp > 0) right++;
        	else {
        		left = right;
        		right = left+1;
        	}
        }
        return ret;
    }
    int maxSubArray2(vector<int>& nums) {    // my second thought faster than 73.66%, 18.90%
    	int retValue = nums[0], accumulateSub = 0;
    	for (vector<int>::size_type i=0;i<nums.size();i++) {
    		accumulateSub += nums[i];
    		retValue = accumulateSub > retValue ? accumulateSub:retValue;
    		accumulateSub = accumulateSub < 0 ? 0:accumulateSub;
    	}
    	return retValue;
    }
    int maxSubArray3(vector<int>& nums) {    // from discussion, a more concise way 10.61% and 48.51%
    	int retValue = nums[0], accumulateSub = 0;
    	for (vector<int>::size_type i=0;i<nums.size();i++) {
    		accumulateSub += nums[i];
    		retValue = std::max(accumulateSub, retValue);
    		accumulateSub = std::max(accumulateSub, 0);
    	}
    	return retValue;
    }
};

int main () {
	Solution sol;
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	std::cout<<sol.maxSubArray3(nums)<<std::endl;
	return 0;
}