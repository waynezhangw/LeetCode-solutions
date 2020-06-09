#include<iostream>
#include<vector>
#include<algorithm> //copy
#include<iterator>  //ostream_iterator

using std::vector;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {   //faster than 6.10%, 5.36% 
        vector<int> vec;
        vector<int> indicate(nums1.size());
        for (vector<int>::size_type i=0;i<nums2.size();i++) {
        	for (vector<int>::size_type j=0;j<nums1.size();j++) {
        		if (nums2[i] == nums1[j] && indicate[j] == 0) {
        			vec.push_back(nums2[i]);
        			indicate[j] = 1;
        			break;
        		}
        	}
        }
        return vec;
    }
    vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {   //faster than 46.44%, 5.36%
        vector<int> vec;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int>::size_type i = 0, j = 0;
        while (i<nums1.size() && j< nums2.size()) {
        	if (nums1[i] == nums2[j]) {
        		vec.push_back(nums1[i]);
        		i++;
        		j++;
        	}
        	else if (nums1[i] < nums2[j]) i++;
        	else j++;
        }
        return vec;
    }
    vector<int> intersect3(vector<int>& nums1, vector<int>& nums2) {   //from other submission: faster than 99.62%, 8.93%
        vector<int> vec;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int>::size_type i = 0, j = 0;
        while (i<nums1.size() && j< nums2.size()) {
        	if (nums1[i] < nums2[j]) i++;                  //the order of the "if else" matters a lot sometimes
        	else if (nums1[i] > nums2[j]) j++;
        	else {
        		vec.push_back(nums1[i]);
        		i++;
        		j++;
        	}
        }
        return vec;
    }
    vector<int> intersect4(vector<int>& nums1, vector<int>& nums2) {   //from other low memory submission: faster than 46.44%, 5.36%
        vector<int> vec;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(vec));
        return vec;
    }
};

int main () {
	Solution sol;
	vector<int> num1 = {5,9};
	vector<int> num2 = {9,4,9,8,4,4,5};
	vector<int> vec = sol.intersect4(num1, num2);
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}