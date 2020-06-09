#include<iostream>
#include<vector>
#include <algorithm>    // std::min

using std::vector;
class Solution {
public:
    int maxArea(vector<int>& height) {          //all test cases passed, but took too long. Status: Time Limit Exceeded
        int area = 0;
        for (int i=0;i<(int)height.size()-1;i++) {                       //Time Limit Exceeded
        	for (vector<int>::size_type j=i+1;j<height.size();j++) {
        		int tempArea = (j-i)*std::min(height[i], height[j]);
        		if (tempArea > area) area = tempArea;
        	}
        }
        return area;
    }
    int maxArea2(vector<int>& height) {       //from other discussion thoughts
        int area = 0;
        vector<int>::size_type i=0, j=height.size()-1;
        while (i<j) {
        	int tempArea = (j-i)*std::min(height[i], height[j]);
        	if (tempArea > area) area = tempArea;
        	height[i]<height[j]?i++:j--;
        }
        return area;
    }
    int maxArea3(vector<int>& height) {       //from other discussion code directly
        int area = 0;
        int i=0, j=height.size()-1;
        while (i<j) {
        	int h = std::min(height[i], height[j]);
        	area = std::max(area, (j-i)*h);
        	while (height[i]<=h && i<j) i++;
        	while (height[j]<=h && i<j) j--;
        }
        return area;
    }
};

int main () {
	Solution sol;
	vector<int> h = {1,8,6,2,5,4,8,3,7,8};
	std::cout<<sol.maxArea3(h)<<std::endl;
	return 0;
}