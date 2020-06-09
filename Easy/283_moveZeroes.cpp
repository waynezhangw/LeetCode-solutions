#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        unsigned int left = 0;
        unsigned int right = 0;
        while (right < nums.size() && left < nums.size()) {
        	while (left < nums.size() && nums[left]!=0) {
        		left++;
        	} 
        	while ( (right < nums.size() && nums[right]==0) || right<left) {   //judge length first
        		right++;
        	}
        	if (left >= nums.size() || right >= nums.size()) break;
        	nums[left] = nums[right];
        	nums[right] = 0;
        	left++;
        	right++;
        }
    }
};

int main(){
	vector<int> test = {1,0,1,0,3,12};
	for(unsigned int i=0;i<test.size();i++) {
		cout<<test[i]<<",";
	}
	cout<<endl;
	Solution solu;
	solu.moveZeroes(test);
	for(unsigned int i=0;i<test.size();i++) {
		cout<<test[i]<<",";
	}
	cout<<endl;
	return 0;
}