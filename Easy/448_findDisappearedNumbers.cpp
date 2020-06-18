#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using std::vector;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {  //space: O(n), runtime O(2n)  79.95% and 18.40%
        vector<int> temp_vec(nums.size(), 0);
        for (auto num: nums) temp_vec[num-1] = 1;
        nums.clear();
        for (vector<int>::size_type i=0;i<temp_vec.size();i++) {
        	if (temp_vec[i] == 0) nums.push_back(i+1);
        }
        return nums;
    }
    vector<int> findDisappearedNumbers2(vector<int>& nums) {  //from discussion, space: O(1), runtime O(n) 42.05% and 38.18%
        for (auto num: nums) {
        	int ind = abs(num) - 1;        //because num could be changed to a negative value 
        	nums[ind] = nums[ind]>0 ? -nums[ind] : nums[ind];
        }
        vector<int> ret;
        for (vector<int>::size_type i=0;i<nums.size();i++) {
        	if (nums[i] > 0) ret.push_back(i+1);
        }
        return ret;
    }
    vector<int> findDisappearedNumbers3(vector<int>& nums) {  //from details, space: O(1), runtime O(n) 80.28% and 79.47%
        for (auto num: nums) {
        	int ind = abs(num) - 1;        //because num could be changed to a negative value 
        	nums[ind] = nums[ind]>0 ? -nums[ind] : nums[ind];
        }
        int count = 0;
        for (vector<int>::size_type i=0;i<nums.size();i++) {
        	if (nums[i] > 0) nums[count++] = i+1;
        }
        return vector<int>(nums.begin(), nums.begin()+count);
    }
};

int main () {
	Solution sol;
	vector<int> vec = {4,3,2,7,8,2,3,1};
	vec = sol.findDisappearedNumbers3(vec);
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}