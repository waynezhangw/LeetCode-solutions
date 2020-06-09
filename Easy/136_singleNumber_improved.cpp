#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (unsigned int i=0;i<nums.size();i++) {
            cout<<x<<" "<<nums[i]<<endl;
        	x = x^nums[i];                //成对 异或处理会让他变过去又变回来
            cout<<x<<" "<<nums[i]<<endl;
        }
        return x;
    }
};

int main() {
	Solution sol;
	vector<int> vec = {4,1,2,1,2,12,12};
	cout<<sol.singleNumber(vec);
	return 0;
}