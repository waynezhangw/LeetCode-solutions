#include<iostream>
#include<vector>
#include<algorithm>   //std::copy, std::fill
#include<iterator>    //std::ostream_iterator

using std::vector;
class Solution {
public:
    void sortColors(vector<int>& nums) {    //49.05% and 20.61%, this is counting sort, two-pass algorithm
        int color[3] = {0,0,0};
        for (vector<int>::size_type i=0;i<nums.size();i++) {
        	if (nums[i]<0 || nums[i]>2) break;
        	color[nums[i]]++;
        }
        int start = 0;
        for (int i=0;i<3;i++) {
        	std::fill(nums.begin()+start, nums.begin()+color[i]+start, i);
        	start += color[i];
        }
    }
    void sortColors2(vector<int>& nums) {      //Runtime Error
    	int left = 0;
        int right = nums.size()-1;
        bool flag = false;
        while (left < right) {
        	while (nums[left] == 0) left++;
        	while (nums[right] == 2) right--;
        	if (nums[left] > nums[right]) std::swap(nums[left], nums[right]);
        	if (nums[left] == nums[right] && nums[left] == 1) {
        		for (int i=left+1;i<(int)nums.size();i++) {
        			if (nums[i] < nums[left]) {
        				std::swap(nums[left], nums[i]);
        				flag = true;
        				break;
        			}
        		}
        		if (!flag) {
        			for (int i=right-1;i>=0;i--) {
        				if (nums[i] > nums[right]) {
        					std::swap(nums[right], nums[i]);
        					flag = true;
        					break;
        				}
        			}
        		}
        		if (!flag) break;
        	}
        	flag = false;
        }
    }
    void sortColors3(vector<int>& nums) {   //cpoied others' code, 49.77% and 59.87%, one-pass algorithm
    	int left = 0;
        int right = nums.size()-1;
        for (int i=0;i<=right;) {
        	if (nums[i]==0) {
        		std::swap(nums[left], nums[i]);
        		i++;
        		left++;
        	}
        	else if (nums[i]==2) {
        		std::swap(nums[right], nums[i]);
        		right--;
        	}
        	else i++;
        }
    }
    void sortColors4(vector<int>& nums) {   //cpoied others' code from details, 49.77% and 22.36%
    	int color[3] = {0,0,0}; //array is more eiifcient than vector           
    	for (auto num: nums) {
        	color[num]++;
        }
        int index = 0;
        for (int i=0;i<3;i++) {
        	for (int j=0;j<color[i];j++) {
        		nums[index++] = i;
        	}
        }
    }

};

int main () {
	Solution sol;
	int num[] = {0,2,1,1,1,2,2,2};
	vector<int> vec(std::begin(num), std::end(num));
	sol.sortColors4(vec);
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}