#include<iostream>
#include<vector>
#include<numeric>

using std::vector;
class Solution {
public:
    int missingNumber(vector<int>& nums) {              //44ms, 18.1MB
        double accum = nums.size()*(1+nums.size())/2.0;
        return int(accum) - std::accumulate(nums.begin(), nums.end(), 0);
    }
    int missingNumber2(vector<int>& nums) {              //40ms, 18.1MB
        return int(nums.size()*(1+nums.size())/2.0) - std::accumulate(nums.begin(), nums.end(), 0);
    }
    int missingNumber3(vector<int>& nums) {              //from disscussion, 40ms, 18MB
        int ret = 0;
        for (auto num: nums) {
        	ret ^= num;
        }
        for (vector<int>::size_type i=0;i<=nums.size();i++) {
        	ret ^= i;
        }
        return ret;
    }
    int missingNumber4(vector<int>& nums) {              //from disscussion, 40ms, 18MB
        int res = nums.size();
        for (vector<int>::size_type i = 0; i < nums.size(); i++) {
            res = res ^ i ^ nums[i];
        }
        return res;
    }
};

int main() {
	Solution sol;
	vector<int> vec = {3,0,1};
	std::cout<<sol.missingNumber4(vec)<<std::endl;
	return 0;
}