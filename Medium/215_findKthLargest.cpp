#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>   // std::greater
#include<queue>

using std::vector;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {  //runtime is low and memory usage is high
		sort(nums.rbegin(), nums.rend());
		return nums[k-1];
	}
	int findKthLargest2(vector<int>& nums, int k) {  //read other people's solution
		std::nth_element(nums.begin(), nums.begin()+k-1, nums.end(), std::greater<int>());
		return nums[k-1];
	}
	int findKthLargest3(vector<int>& nums, int k) {  //read other people's solution
		std::partial_sort(nums.begin(), nums.begin()+k, nums.end(), std::greater<int>());
		return nums[k-1];
	}
	int findKthLargest4(vector<int>& nums, int k) {  //min-heap using priority_queue
		std::priority_queue<int, vector<int>, std::greater<int>> pq;
		for (int num : nums) {
			pq.push(num);
			if (int(pq.size())>k) {
				pq.pop();
			}
		}
		return pq.top();
	}
};

int main()
{
	Solution sol;
	vector<int> vec = { 3,2,3,1,2,4,5,5,6 };
	std::cout << sol.findKthLargest4(vec, 4) << std::endl;
	return 0;
}