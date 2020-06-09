#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (unsigned int i=0;i<nums.size();i++) {
        	int singleNum = count(nums.begin(), nums.end(), nums[i]);  //时间复杂度相当于n平方了
        	if (singleNum == 1) {
        		return nums[i];
        	}
        }
        return 0;
    }
};

int main() {
	Solution sol;
	vector<int> vec = {4,1,2,1,2};
	cout<<sol.singleNumber(vec);
	return 0;
}